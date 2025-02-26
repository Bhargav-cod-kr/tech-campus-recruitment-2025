#include <iostream>
#include <fstream>
#include <string>

using namespace std; // Using namestd as requested

// Function to extract logs for the given date
void extract_logs(const string &log_file, const string &date) {
    ifstream infile(log_file); // Open the large log file
    if (!infile.is_open()) {
        cerr << "Error: Unable to open log file." << endl;
        return;
    }

    string output_file = "output/output_" + date + ".txt";
    ofstream outfile(output_file); // Output file to store the logs

    if (!outfile.is_open()) {
        cerr << "Error: Unable to create output file." << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {
        // Check if the line starts with the requested date
        if (line.rfind(date, 0) == 0) {
            outfile << line << endl;
        }
    }

    infile.close();
    outfile.close();
    cout << "Logs for " << date << " saved in: " << output_file << endl;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <log_file> <YYYY-MM-DD>" << endl;
        return 1;
    }

    string log_file = argv[1];  // Log file path
    string date = argv[2];      // Date to filter logs

    extract_logs(log_file, date);
    return 0;
}
