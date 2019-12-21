#ifndef CONFIG_H_IN
#define CONFIG_H_IN

#include <string>

namespace projectdefinitions {
static std::string getProjectName() {
    return "jsontree";
}

static std::string getProjectVersion() {
    return "1.0";
}

static std::string getApplicationID() {
    return "tr0y.me.jsontree";
}

static std::string getApplicationPrefix() {
    return "/tr0y/me/jsontree/";
}

static std::string getGeneratedFilesDirectory() {
    return "/home/troy/Projects/jsontree/cmake-build-debug/generated";
}

static std::string getGeneratedDataDirectory() {
    return "/home/troy/Projects/jsontree/cmake-build-debug/generated/data";
}
}

#endif  // CONFIG_H_IN
