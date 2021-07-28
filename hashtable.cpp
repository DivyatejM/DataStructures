#include<bits/stdc++.h>
using namespace std;
class hashTable {
  private:
    static const int hashSize =10;
    list<pair<int,string>> table[hashSize];
  public: 
    bool isEmpty() const;
    int hashFunction(int key);
    void insert(int key, string value);
    void remove(int key);
    string search(int key);
    void printTable();
};
bool hashTable:: isEmpty() const {
  int sum=0;
  for (int i=0;i<hashSize;i++) 
    sum=sum+table[i].size();

  if(!sum)
    return true;
  return false;
}

int hashTable:: hashFunction(int key) {
  return (key%hashSize);
}

void hashTable::insert(int key, string value) {
  int hashValue=hashFunction(key);
  auto & cell=table[hashValue];
  auto itr=begin(cell);
  bool keyExists=false;
  for(;itr!=end(cell);itr++) {
    if(itr->first==key) {
      keyExists=true;
      itr->second=value;
      cout<<"Key Exists. Value Replaced.\n";
      break;
    }
  }
  if(!keyExists) {
    cell.emplace_back(key, value);
  }
}

void hashTable::remove(int key) {
  int hashValue=hashFunction(key);
  auto & cell=table[hashValue];
  auto itr=begin(cell);
  bool keyExists=false;
  for(;itr!=end(cell);itr++) {
    if(itr->first==key) {
      keyExists=true;
      itr=cell.erase(itr);
      cout<<"Item Removed.\n";
      break;
    }
  }
  if(!keyExists)
    cout<<"Item Not found.\n";
}
void hashTable::printTable() {
  for(int i=0;i<hashSize;i++) {
    if(table[i].size()==0) continue;
    auto itr = table[i].begin();
    for(;itr!=table[i].end();itr++) {
      cout<<"Key : "<<itr->first<<" Value : "<<itr->second<<endl;
    }
  }
}

int main() {
  hashTable ht;
  if(ht.isEmpty())
    cout<<"Correct Answer. Empty\n";
  else {
    cout<<"Incorrect Answer. Not empty\n";
  }
  ht.insert(728,"raj");
  ht.insert(721,"ram");
  ht.insert(723,"shyam");
  ht.insert(724,"radha");
  ht.insert(728,"rahul");
  ht.printTable();

  ht.remove(728);
  ht.remove(332);

  if(ht.isEmpty())
    cout<<"Incorrect Answer. Empty\n";
  else {
    cout<<"Correct Answer. Not empty\n";
}
return 0;
}