#include <string>
#include <vector>

class Computer {
private:
    std::string model;
    std::string processor;
    int ram;
    int hdd;
    double price;

public:

    Computer();


    ~Computer();


    std::string getModel() const { return model; }
    std::string getProcessor() const { return processor; }
    int getRAM() const { return ram; }
    int getHDD() const { return hdd; }
    double getPrice() const { return price; }

    void setModel(const std::string& m) { model = m; }
    void setProcessor(const std::string& p) { processor = p; }
    void setRAM(int r) { ram = r; }
    void setHDD(int h) { hdd = h; }
    void setPrice(double p) { price = p; }


    void display() const;


    static Computer inputFromKeyboard();


    bool hasProcessor(const std::string& targetProcessor) const;
    bool hasRAMGreaterThan(int minRAM) const;
    bool hasPriceLessThan(double maxPrice) const;
};


bool validateString(const std::string& str);
bool validateNumber(int num);
bool validatePrice(double price);

void loadDataFromFile(const std::string& filename, std::vector<Computer>& computers);
void addComputerToVector(std::vector<Computer>& computers, const Computer& comp);
void displayAllComputers(const std::vector<Computer>& computers);
void displayComputersByProcessor(const std::vector<Computer>& computers, const std::string& processor);
void displayComputersByRAM(const std::vector<Computer>& computers, int minRAM);
void displayComputersByPrice(const std::vector<Computer>& computers, double maxPrice);