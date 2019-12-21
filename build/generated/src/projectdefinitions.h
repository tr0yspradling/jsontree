#ifndef CONFIG_H_IN
#define CONFIG_H_IN

#include <string>

namespace projectdefinitions {
static std::string getProjectName() {
    return "ApplicationTemplate";
}

static std::string getProjectVersion() {
    return "1.0";
}

static std::string getApplicationID() {
    return "org.gtkmm.ApplicationTemplate";
}

static std::string getApplicationPrefix() {
    return "/org/gtkmm/ApplicationTemplate/";
}

static std::string getGeneratedFilesDirectory() {
    return "/home/troy/Projects/test/build/generated";
}

static std::string getGeneratedDataDirectory() {
    return "/home/troy/Projects/test/build/generated/data";
}
}

#endif  // CONFIG_H_IN
