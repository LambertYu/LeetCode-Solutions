#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class ShoppingRecord{
public:
  ShoppingRecord(double paid, const std::string& whom, const std::vector<bool> share) : payment(paid), who_paid(whom), who_share(share){}
  double getPayment() const { return payment; }
  const std::string& getWhoPaid() const {return who_paid;}
  const std::vector<bool>& getWhoShare() const { return who_share;}
  int getShareNum() {
    int count = 0;
    for (size_t i = 0; i < 4; i++) {
      if(who_share[i]) count++;
    }
    return count;
  }
private:
  double payment;
  std::string who_paid;
  std::vector<bool> who_share;
};

int main(int argc, char* argv[]){
  // command line arguments & opening files
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " input.txt output.txt" << std::endl;
    exit(1);
  }
  std::ifstream istr(argv[1]);
  if (!istr) {
    std::cerr << "ERROR: could not open " << argv[1] << std::endl;
    exit(1);
  }
  std::ofstream ostr(argv[2]);
  if (!ostr) {
    std::cerr << "ERROR: could not open " << argv[2] << std::endl;
    exit(1);
  }

  // the master container of polygons
  std::vector<ShoppingRecord> records;

  // read the input file one line at a time
  std::string line;
  while (getline(istr,line)) {
    std::stringstream ss(line);
    double payment;
    std::string who_paid;
    bool a;
    std::vector<bool> shared;
    if (!(ss >> payment)) continue;
    ss >> who_paid;
    while (ss >> a) {
      shared.push_back(a);
    }
    ShoppingRecord aRecord(payment,who_paid,shared);
    records.push_back(aRecord);
  }
  std::vector<double> receive_pay(4,0);
  for (size_t i = 0; i < records.size(); i++) {
    int count = records[i].getShareNum();
    double payment = records[i].getPayment();
    for(int j = 0; j < 4; j++){
      if(records[i].getWhoShare()[j]){
        receive_pay[j] += payment / count;
      }
    }
  }

  std::cout << "Qiu  : " << receive_pay[0] << '\n';
  std::cout << "Yu   : " << receive_pay[1] << '\n';
  std::cout << "Lili : " << receive_pay[2] << '\n';
  std::cout << "Yi   : " << receive_pay[3] << '\n';

}
