#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void list_files(const char *path, int indent) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if (!(dir = opendir(path))) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            printf("d %*s%s\n", indent, "", entry->d_name);
            char sub_path[1024];
            snprintf(sub_path, sizeof(sub_path), "%s/%s", path, entry->d_name);
            list_files(sub_path, indent + 4);
        } else {
            stat(entry->d_name, &file_stat);
            printf("f %*s%s\n", indent, "", entry->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [path]\n", argv[0]);
        return 1;
    }

    printf("%s/ [directory]\n", argv[1]);
    list_files(argv[1], 2);

    return 0;
}