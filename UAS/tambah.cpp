#include <iostream>

int stokObat(int line_number) {
  ifstream file;
  int result;
  
  if (line_number <= 0) {
    cout << "Line number must be >= 1" << endl;
    return 1;
  }
  
  file.open("data.txt");
  
  if (file.fail()) {
    cout << "File failed to open." << endl;
    return 1; 
  }
  
  int current_line = 0;
  string line;
  
  while (!file.eof()) {
    current_line++;

    getline(file, line);

    if (current_line == line_number) break;
  }
  
  if (current_line < line_number) {
    cout << "Line not found!" << endl;
    cout << "File contains " << current_line;
    cout << " lines total." << endl;
  } else {
    result = convertStringToInt(lastWord(line));
  }
  
  
  file.close();

  return result; 
}
