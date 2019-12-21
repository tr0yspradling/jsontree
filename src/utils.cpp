#include "utils.h"

std::string read_file(std::string file_path) {
    std::ifstream ifs(file_path);
    std::string content((std::istreambuf_iterator<char>(ifs)),
                        std::istreambuf_iterator<char>());

    if (content.empty()) {
        return "";
    }

    return content;
}
