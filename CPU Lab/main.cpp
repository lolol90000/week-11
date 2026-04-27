#include <iostream>
#include <string>
using namespace std;

class CPU {
private:
    string id;
    int ff, mf, cof, cot;
    double cmips;

    void computeMIPS() {
        cmips = cof * 1000000.0; // CPI = 1
    }

public:
    CPU() {
        id = "";
        ff = 2000;
        mf = 5000;
        cof = 2000;
        cot = 122;
        computeMIPS();
    }

    CPU(string cpuId, int fundamental, int maximum, int currentFreq, int currentTemp) {
        id = cpuId;
        ff = fundamental;
        mf = maximum;
        cof = currentFreq;
        cot = currentTemp;
        computeMIPS();
    }

    void display() {
        cout << "CPU ID: " << id << endl;
        cout << "Fundamental Frequency: " << ff << " Hz" << endl;
        cout << "Maximum Frequency: " << mf << " Hz" << endl;
        cout << "Current Frequency: " << cof << " Hz" << endl;
        cout << "Current Temperature: " << cot << " F" << endl;
        cout << "Current MIPS: " << cmips << endl;
    }

    void setTemperature(int newTemp) {
        cot = newTemp;

        if (cot < 176) {
            cof += 200;
            if (cof > mf)
                cof = mf;
        }
        else if (cot > 176) {
            cof -= 200;
            if (cof < ff)
                cof = ff;
        }

        computeMIPS();
    }

    double getMIPS() {
        return cmips;
    }
};

// =================== Main Program ===================
int main() {
    const int N = 4;
    CPU cluster[N] = {
        CPU("001", 2000, 4800, 2800, 132),
        CPU("002", 2200, 5000, 3200, 131),
        CPU("003", 2100, 4900, 3400, 142),
        CPU("004", 2500, 4500, 3700, 144)
    };

    int choice;
    do {
        cout << "\n===== CPU Cluster Menu =====\n";
        cout << "1. Display all CPUs\n";
        cout << "2. Display one CPU\n";
        cout << "3. Set temperature of one CPU\n";
        cout << "4. Display total MIPS of cluster\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < N; i++) {
                cout << endl;
                cluster[i].display();
            }
        }
        else if (choice == 2) {
            int index;
            cout << "Enter CPU number 1-4: ";
            cin >> index;

            if (index >= 1 && index <= N) {
                cluster[index - 1].display();
            }
            else {
                cout << "Invalid CPU number.\n";
            }
        }
        else if (choice == 3) {
            int index;
            int newTemp;

            cout << "Enter CPU number 1-4: ";
            cin >> index;

            if (index >= 1 && index <= N) {
                cout << "Enter new temperature: ";
                cin >> newTemp;

                cluster[index - 1].setTemperature(newTemp);

                cout << "Updated CPU information:\n";
                cluster[index - 1].display();
            }
            else {
                cout << "Invalid CPU number.\n";
            }
        }
        else if (choice == 4) {
            double totalMIPS = 0;

            for (int i = 0; i < N; i++) {
                totalMIPS += cluster[i].getMIPS();
            }

            cout << "Total MIPS of cluster: " << totalMIPS << endl;
        }

    } while (choice != 5);

    cout << "Program exited.\n";
    return 0;
}