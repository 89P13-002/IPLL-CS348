#include <bits/stdc++.h>
using namespace std;

map<string, string> opcodeTable = {
            {"LDA", "00"},
            {"LDX", "04"},
            {"LDL", "08"},
            {"STA", "0C"},
            {"STX", "10"},
            {"STL", "14"}, 
            {"LDCH", "50"}, 
            {"STCH", "54"}, 
            {"ADD", "18"}, 
            {"SUB", "1C"},
            {"MUL", "20"},
            {"DIV", "24"},
            {"COMP", "28"},
            {"J", "3C"},
            {"JLT", "38"}, 
            {"JEQ", "30"}, 
            {"JGT", "34"}, 
            {"JSUB", "48"},
            {"RSUB", "4C"},
            {"AND", "40"},   
            {"TIX", "2C"},
            {"TD", "E0"}, 
            {"RD", "D8"}, 
            {"WD", "DC"}
};

map<string, int> symbolTable;
int startAdd = 0;
int programLength = 0;

string to_hex(int value) {
    stringstream ss;
    ss << hex << uppercase << value;
    return ss.str();
}

void padStart(string& str, int length, char pad) {
    if(str.length() < length) {
        str.insert(0, length - str.length(), pad);
    }
    return ; 
}

void removeEmpty(string& str) {
    if(str.find(' ') != -1){
        str = str.substr(0,str.find(' '));
    }
    return;
}

void padEnd(string& str, int length, char pad) {
    if(str.length() < length) {
        str.append(length - str.length(), pad);
    }
    return ;
}

string constConvert(string operand) {
    if(operand[0] == 'C') {
        string result;
        for(int i = 2; i < operand.length() - 1; i++) {
            stringstream ss;
            ss << hex << uppercase << setw(2) << setfill('0') << (int)operand[i];
            result += ss.str();
        }
        return result;
    } 
    else if(operand[0] == 'X') {
        return operand.substr(2, operand.length() - 3);
    } 
    else {
        int value = stoi(operand);
        stringstream ss;
        ss << hex << uppercase << setw(6) << setfill('0') << value;
        return ss.str();
    }
}

vector<string> parseFun(int index, string& data) {
    vector<string> res(3, "");
    int counter = 0;
    
    for(int i = index; i < data.size(); i++) {
        if(data[i] != ' ') {
            res[counter] += data[i];
        } 
        else {
            while(i < data.size() && data[i] == ' ') {
                i++;
            }
            counter++;
            i--;
        }
        if(counter >= 3) break;
    }
    
    return res;
}

void passOne() {
    // Pass One implementation remains the same
    ifstream input("sample_input.txt");
    ofstream intermd("intermediate.txt");
    ofstream symbolTableFile("symbolTable.txt");
    
    string line;
    int locctr = 0, start = 0;
    bool startFound = false;
    int symbolIndex = 1;
    
    while(getline(input, line)) {
        if(line.empty() || line[0] == '.') {
            intermd << left << setw(8) << " "<< line << endl;
            continue;
        }
                
        vector<string> parts = parseFun(0, line);
        string label = parts[0];
        string opcode = parts[1];
        string operand = parts[2];
        
        if(opcode == "START") {
            start = stoi(operand, nullptr, 16);
            locctr = start;
            startAdd = start;
            startFound = true;
            
            intermd << left << setw(8) << hex << uppercase << locctr 
                    << setw(10) << label 
                    << setw(10) << opcode 
                    << operand << endl;
            continue;
        }
        
        if(!startFound) {
            continue;
        }
        
        if(opcode == "END") {
            programLength = locctr - start;
            intermd << left << setw(8) << hex << uppercase << locctr 
                    << setw(10) << label 
                    << setw(10) << opcode 
                    << operand << endl;
            break;
        }
        
        intermd << left << setw(8) << hex << uppercase << locctr 
                << setw(10) << label 
                << setw(10) << opcode 
                << operand << endl;
        
        if(!label.empty() && label != ".") {
            if(symbolTable.find(label) == symbolTable.end()) {
                symbolTable[label] = locctr;
                symbolTableFile << left << setw(15) << label 
                           << setw(15) << hex << uppercase << locctr 
                           << symbolIndex++ << endl;
            } 
            else {
                cerr << "Duplicate symbol: " << label << endl;
            }
        }
        
        
        if(opcodeTable.find(opcode) != opcodeTable.end()) {
            locctr += 3;
        } 
        else if(opcode == "RESB") {
            locctr += stoi(operand);
        }
        else if(opcode == "WORD") {
            locctr += 3;
        } 
        else if(opcode == "RESW") {
            locctr += 3 * stoi(operand);
        } 
        else if(opcode == "BYTE") {
            if(operand[0] == 'C') {
                locctr += operand.length() - 3;
            } 
            else if(operand[0] == 'X') {
                locctr += (operand.length() - 3) / 2;
            }
        } 
        else {
            cerr << "Invalid opcode: " << opcode << endl;
        }
    }
    
    input.close();
    intermd.close();
    symbolTableFile.close();
}

void passTwo() {
    ifstream intermd("intermediate.txt");
    ofstream output("machineCode.txt");
    ofstream outputObj("output.txt");
    
    string data;
    string currentRecord = "";
    string startAddress = "";
    
    while(getline(intermd, data)) {
        if(data.find(".") != -1) {
            output << endl;
            continue;
        }
        
        string label = "", opcode = "", operand = "", locctr = "", objcode = "";
        
        locctr = data.substr(0, 6);
        removeEmpty(locctr);
        vector<string> ans = parseFun(8, data);
        label = ans[0];
        opcode = ans[1];
        operand = ans[2];
        if(opcode == "START") {
            output << left << setw(10) << locctr 
                   << setw(15) << label 
                   << setw(15) << opcode 
                   << operand << endl;
            
            string progName = label;
            padEnd(progName, 6, ' ');
            outputObj << "H" << progName 
                     << setw(6) << setfill('0') << right << hex << uppercase << stoi(operand, nullptr, 16)
                     << setw(6) << setfill('0') << programLength << endl;
            
            startAddress = locctr;
            continue;
        }
        
        if(opcode == "END") {
            output << left << setw(10) << locctr 
                   << setw(15) << label 
                   << setw(15) << opcode 
                   << operand << endl;
            
            // if anything remain to write
            if(!currentRecord.empty()) {
                string recordLength = to_hex(currentRecord.length() / 2);
                padStart(recordLength, 2, '0');
                outputObj << "T" << setw(6) << setfill('0') << right << startAddress 
                         << recordLength << currentRecord << endl;
            }
            
            // last line
            outputObj << "E" << setw(6) << setfill('0') << right << hex << uppercase << startAdd << endl;
            break;
        }
        
        // Generating object code
        if(opcodeTable.find(opcode) != opcodeTable.end()) {
            if(symbolTable.find(operand) != symbolTable.end()) {
                objcode = opcodeTable[opcode] + to_hex(symbolTable[operand]);
                padEnd(objcode, 6, '0');
            } 
            else if(operand.find(",X") != -1) {
                string baseOperand = operand.substr(0, operand.find(",X"));
                if(symbolTable.find(baseOperand) != symbolTable.end()) {
                    int address = symbolTable[baseOperand] + 0x8000;  // base reg setup
                    objcode = opcodeTable[opcode] + to_hex(address);
                    padEnd(objcode, 6, '0');
                } 
                else {
                    objcode = opcodeTable[opcode] + "0000";
                }
            } 
            else if(opcode == "RSUB") {
                objcode = opcodeTable[opcode] + "0000";
            } 
            else {
                objcode = opcodeTable[opcode] + "0000";
            }
        } 
        else if(opcode == "BYTE" || opcode == "WORD") {
            objcode = constConvert(operand);
        }
        
        output << left << setw(10) << locctr 
               << setw(15) << label 
               << setw(15) << opcode 
               << setw(15) << operand 
               << objcode << endl;
        
        if(opcode == "RESW" || opcode == "RESB") {
            if(!currentRecord.empty()) {
                string recordLength = to_hex(currentRecord.length() / 2);
                padStart(recordLength, 2, '0');
                outputObj << "T" << setw(6) << setfill('0') << right << startAddress 
                         << recordLength << currentRecord << endl;
                currentRecord = "";
            }
        }
        else if(!objcode.empty()) {
            if(currentRecord.empty()) {
                startAddress = locctr;
            }
            
            if(currentRecord.length() + objcode.length() > 60) {
                string recordLength = to_hex(currentRecord.length() / 2);
                padStart(recordLength, 2, '0');
                outputObj << "T" << setw(6) << setfill('0') << right << startAddress 
                         << recordLength << currentRecord << endl;
                currentRecord = objcode;
                startAddress = locctr;
            }
            else {
                currentRecord += objcode;
            }
        }
    }
    
    intermd.close();
    output.close();
    outputObj.close();
}

int main() {
    cout << "Pass one started. \n";
    passOne();
    cout << "Pass two started. \n";
    passTwo();
    cout << "Done all passes. \n";
    return 0;
}