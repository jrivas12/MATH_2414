#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>

struct LoginAttempt {
    std::string ip;
};

double entropy(const std::string& ip) {
    std::unordered_map<char, int> freq;
    for (char c : ip) {
        freq[c]++;
    }

    double ent = 0.0;
    int length = ip.size();
    for (const auto& pair : freq) {
        double p = static_cast<double>(pair.second) / length;
        ent -= p * std::log2(p);
    }
    return ent;
}

void flag_as_suspicious(const std::string& ip) {
    std::cout << "Suspicious IP flagged: " << ip << std::endl;
}

int main() {
    std::vector<LoginAttempt> login_attempts = {
        {"192.168.1.1"},
        {"000.000.000.000"},
        {"182.34.90.12"},
        {"111.111.111.111"}
    };

    double threshold = 2.5; 

    for (const auto& attempt : login_attempts) {
        if (entropy(attempt.ip) < threshold) {
            flag_as_suspicious(attempt.ip);
        }
    }
    return 0;
}
