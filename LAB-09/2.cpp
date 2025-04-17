#include <iostream>
#include <vector>
#include <string>

class Logger {
private:
    std::vector<std::string> logMessages;
    const size_t MAX_LOGS = 1000;

    void storeLog(const std::string& severity, const std::string& message, const std::string& module) {
        std::string formatted = "[" + severity + "] (" + module + "): " + message;

        if (logMessages.size() >= MAX_LOGS) {
            for (size_t i = 1; i < logMessages.size(); ++i) {
                logMessages[i - 1] = logMessages[i];
            }
            logMessages.pop_back(); 
        }

        logMessages.push_back(formatted);
    }

public:
    void logInfo(const std::string& message, const std::string& module) {
        storeLog("INFO", message, module);
    }

    void logWarning(const std::string& message, const std::string& module) {
        storeLog("WARNING", message, module);
    }

    void logError(const std::string& message, const std::string& module) {
        storeLog("ERROR", message, module);
    }

    friend class Auditor;
};

class Auditor {
private:
    bool authenticated;

public:
    Auditor(bool auth) : authenticated(auth) {}

    void retrieveLogs(const Logger& logger) const {
        if (!authenticated) {
            std::cout << "Access Denied: Auditor not authenticated.\n";
            return;
        }

        std::cout << "\n--- Audit Log Start ---\n";
        for (const std::string& log : logger.logMessages) {
            std::cout << log << "\n";
        }
        std::cout << "--- Audit Log End ---\n";
    }
};

int main() {
    Logger logger;

    logger.logInfo("System started", "Core");
    logger.logWarning("Low memory detected", "Memory Manager");
    logger.logError("Crash in module", "Graphics Engine");

    Auditor badAuditor(false);
    badAuditor.retrieveLogs(logger);

    Auditor goodAuditor(true);
    goodAuditor.retrieveLogs(logger);

    return 0;
}
