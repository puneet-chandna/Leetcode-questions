class Spreadsheet {
private:
    unordered_map<string, int> cellValue;

    int getTokenValue(const string &token) {
        if (isdigit(token[0])) {
            return stoi(token);
        } else {
            auto it = cellValue.find(token);
            if (it == cellValue.end()) return 0;
            return it->second;
        }
    }

public:
    Spreadsheet(int rows) {
        
    }

    void setCell(string cell, int value) {
        cellValue[cell] = value;
    }

    void resetCell(string cell) {
       
        cellValue.erase(cell);
    }

    int getValue(string formula) {
        
        int plusPos = formula.find('+');
        
        string left = formula.substr(1, plusPos - 1);
        
        string right = formula.substr(plusPos + 1);
        int lv = getTokenValue(left);
        int rv = getTokenValue(right);
        return lv + rv;
        
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */