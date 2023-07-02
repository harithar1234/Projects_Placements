// AI20BTECH11010-Haritha.R  -Lab 8 exam

//C++ program to convert a given RISC-V machine code to their equivalent assembly syntax

#include <string>
#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include<string.h>


using namespace std;

void register_decode(array<int, 5> &register_code, string &register_name) {
  if (std::equal(std::begin(register_code), std::end(register_code),
                 std::begin({0, 0, 0, 0, 0}))) {
    register_name = "x0";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 0, 0, 0, 1}))) {
    register_name = "x1";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 0, 0, 1, 0}))) {
    register_name = "x2";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 0, 0, 1, 1}))) {
    register_name = "x3";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 0, 1, 0, 0}))) {
    register_name = "x4";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 0, 1, 0, 1}))) {
    register_name = "x5";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 0, 1, 1, 0}))) {
    register_name = "x6";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 0, 1, 1, 1}))) {
    register_name = "x7";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 1, 0, 0, 0}))) {
    register_name = "x8";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 1, 0, 0, 1}))) {
    register_name = "x9";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 1, 0, 1, 0}))) {
    register_name = "x10";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 1, 0, 1, 1}))) {
    register_name = "x11";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 1, 1, 0, 0}))) {
    register_name = "x12";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 1, 1, 0, 1}))) {
    register_name = "x13";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 1, 1, 1, 0}))) {
    register_name = "x14";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({0, 1, 1, 1, 1}))) {
    register_name = "x15";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 0, 0, 0, 0}))) {
    register_name = "x16";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 0, 0, 0, 1}))) {
    register_name = "x17";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 0, 0, 1, 0}))) {
    register_name = "x18";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 0, 0, 1, 1}))) {
    register_name = "x19";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 0, 1, 0, 0}))) {
    register_name = "x20";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 0, 1, 0, 1}))) {
    register_name = "x21";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 0, 1, 1, 0}))) {
    register_name = "x22";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 0, 1, 1, 1}))) {
    register_name = "x23";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 1, 0, 0, 0}))) {
    register_name = "x24";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 1, 0, 0, 1}))) {
    register_name = "x25";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 1, 0, 1, 0}))) {
    register_name = "x26";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 1, 0, 1, 1}))) {
    register_name = "x27";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 1, 1, 0, 0}))) {
    register_name = "x28";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 1, 1, 0, 1}))) {
    register_name = "x29";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 1, 1, 1, 0}))) {
    register_name = "x30";
  } else if (std::equal(std::begin(register_code), std::end(register_code),
                        std::begin({1, 1, 1, 1, 1}))) {
    register_name = "x31";
  }
}

void function_search(array<int, 7> &opcode, array<int, 3> &func3,
                     array<int, 7> &func7, string &function_name) {

  // R-type instructions
  if (std::equal(std::begin(opcode), std::end(opcode),
                 std::begin({0, 1, 1, 0, 0, 1, 1}))) {

    if (std::equal(std::begin(func3), std::end(func3), std::begin({0, 0, 0}))) {

      if (std::equal(std::begin(func7), std::end(func7),
                     std::begin({0, 0, 0, 0, 0, 0, 0}))) {
        function_name = "add";
      } else if (std::equal(std::begin(func7), std::end(func7),
                            std::begin({0, 1, 0, 0, 0, 0, 0}))) {
        function_name = "sub";
      }
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 1, 1}))) {
      function_name = "and";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 1, 0}))) {
      function_name = "or";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 0, 0}))) {
      function_name = "xor";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({0, 0, 1}))) {
      function_name = "sll";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 0, 1}))) {

      if (std::equal(std::begin(func7), std::end(func7),
                     std::begin({0, 0, 0, 0, 0, 0, 0}))) {
        function_name = "srl";
      } else if (std::equal(std::begin(func7), std::end(func7),
                            std::begin({0, 1, 0, 0, 0, 0, 0}))) {
        function_name = "sra";
      }
    }

  }

  // I-type instructions (non load )
  else if (std::equal(std::begin(opcode), std::end(opcode),
                      std::begin({0, 0, 1, 0, 0, 1, 1}))) {

    if (std::equal(std::begin(func3), std::end(func3), std::begin({0, 0, 0}))) {
      function_name = "addi";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 1, 1}))) {
      function_name = "andi";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 1, 0}))) {
      function_name = "ori";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 0, 0}))) {
      function_name = "xori";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({0, 0, 1}))) {
      function_name = "slli";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 0, 1}))) {
      function_name = "srli";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 0, 1}))) {
      function_name = "srai";
    }
  }

  // I-type instructions (load )
  else if (std::equal(std::begin(opcode), std::end(opcode),
                      std::begin({0, 0, 0, 0, 0, 1, 1}))) {

    if (std::equal(std::begin(func3), std::end(func3), std::begin({0, 0, 0}))) {
      function_name = "lb";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({0, 0, 1}))) {
      function_name = "lh";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({0, 1, 0}))) {
      function_name = "lw";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({0, 1, 1}))) {
      function_name = "ld";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 0, 0}))) {
      function_name = "lbu";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 0, 1}))) {
      function_name = "lhu";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 1, 0}))) {
      function_name = "lwu";
    }

  }

  // S-type instructions
  else if (std::equal(std::begin(opcode), std::end(opcode),
                      std::begin({0, 1, 0, 0, 0, 1, 1}))) {
    if (std::equal(std::begin(func3), std::end(func3), std::begin({0, 0, 0}))) {
      function_name = "sb";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({0, 0, 1}))) {
      function_name = "sh";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({0, 1, 0}))) {
      function_name = "sw";
    } else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({0, 1, 1}))) {
      function_name = "sd";
    }
  }

  // B-type instructions
  else if (std::equal(std::begin(opcode), std::end(opcode),
                      std::begin({1, 1, 0, 0, 0, 1, 1}))) {

    if (std::equal(std::begin(func3), std::end(func3), std::begin({0, 0, 0}))) {
      function_name = "beq";
    } 
    else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({0, 0, 1}))) {
      function_name = "bne";
    } 
    else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 0, 0}))) {
      function_name = "blt";
    }
    else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 0, 1}))) {
      function_name = "bge";
    } 
    else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 1, 0}))) {
      function_name = "bltu";
    } 
    else if (std::equal(std::begin(func3), std::end(func3),
                          std::begin({1, 1, 1}))) {
      function_name = "bgeu";
    }
  }

  // J-type instruction ( jal)
  else if (std::equal(std::begin(opcode), std::end(opcode),
                      std::begin({1, 1, 0, 1, 1, 1, 1}))) {
    function_name = "jal";
  }
  // I-type instruction ( jalr)
  else if (std::equal(std::begin(opcode), std::end(opcode),
                      std::begin({1, 1, 0, 0, 1, 1, 1}))) {
    function_name = "jalr";
  }
  // U-type instruction ( lui)
  else if (std::equal(std::begin(opcode), std::end(opcode),
                      std::begin({0, 1, 1, 0, 1, 1, 1}))) {
    function_name = "lui";
  }
}

void binary_to_decimal_12bit(array<int, 12> &imm_arr, int *num) {
  *num = 0 ;  
  
  for(int i = 0 ; i < 12 ; i++)
    {(*num) = ((*num) *2) + imm_arr[i] ;}
   
   if((*num)>2047) // signed number >2047 is not possible with 12 bits
     {(*num)=(*num)- (pow(2,12)) ;} 
}

void binary_to_decimal_7bit(array<int, 7>& imm_arr, int* num) {
  *num = 0;

  for (int i = 0; i < 7; i++) {
    (*num) = ((*num) * 2) + imm_arr[i];
  }

  if ((*num) > 63) { // signed number > 63 is not possible with 7 bits
    (*num) = (*num) - (pow(2,7))  ;
  }
}


char getHexCharacter(string str)
{
	if(str.compare("1111") == 0) return 'F';
	else if(str.compare("1110") == 0) return 'E';
	else if(str.compare("1101")== 0) return 'D';
	else if(str.compare("1100")== 0) return 'C';
	else if(str.compare("1011")== 0) return 'B';
	else if(str.compare("1010")== 0) return 'A';
	else if(str.compare("1001")== 0) return '9';
	else if(str.compare("1000")== 0) return '8';
	else if(str.compare("0111")== 0) return '7';
	else if(str.compare("0110")== 0) return '6';
	else if(str.compare("0101")== 0) return '5';
	else if(str.compare("0100")== 0) return '4';
	else if(str.compare("0011")== 0) return '3';
	else if(str.compare("0010")== 0) return '2';
	else if(str.compare("0001")== 0) return '1';
	else if(str.compare("0000")== 0) return '0';
	else return'N';
}

string binary_to_hex(string binary_digits)
{
	string hex_result = "";
	for(int i = 0; i < binary_digits.length(); i = i+4)
	{
		hex_result += getHexCharacter(binary_digits.substr(i,4));
	}
	return hex_result;
}



string hexcode_to_binarycode(string &hexadecimal_code ){
		
    int i=0, chk=0;
    char binaryNum[32]="";

    while(hexadecimal_code[i])
    {
        switch(hexadecimal_code[i])
        {
            case '0':
                strcat(binaryNum, "0000");
                break;
            case '1':
                strcat(binaryNum, "0001");
                break;
            case '2':
                strcat(binaryNum, "0010");
                break;
            case '3':
                strcat(binaryNum, "0011");
                break;
            case '4':
                strcat(binaryNum, "0100");
                break;
            case '5':
                strcat(binaryNum, "0101");
                break;
            case '6':
                strcat(binaryNum, "0110");
                break;
            case '7':
                strcat(binaryNum, "0111");
                break;
            case '8':
                strcat(binaryNum, "1000");
                break;
            case '9':
                strcat(binaryNum, "1001");
                break;
            case 'A':
            case 'a':
                strcat(binaryNum, "1010");
                break;
            case 'B':
            case 'b':
                strcat(binaryNum, "1011");
                break;
            case 'C':
            case 'c':
                strcat(binaryNum, "1100");
                break;
            case 'D':
            case 'd':
                strcat(binaryNum, "1101");
                break;
            case 'E':
            case 'e':
                strcat(binaryNum, "1110");
                break;
            case 'F':
            case 'f':
                strcat(binaryNum, "1111");
                break;
            default:
                chk = 1;
                break;
        }
        i++;
    }
    if(chk==0)
        return(string(binaryNum));
    else 
        return("none");}

              
int main() {

  ifstream fptr("README.txt"); // contains hex digits
   
  int Labels_tracking[20]; 
    // as maximum 20 labels are allowed since code itself is 20 lines

  char strings_label_names[20][8]= { "Label0","Label1","Label2","Label3","Label4","Label5","Label6",
  "Label7","Label8","Label9","Label10","Label11","Label12","Label13","Label14","Label15",
  "Label16","Label17","Label18","Label19" };
  
  for(int j=0; j<19 ;j++ )
  {Labels_tracking[j]= -700 ; } // randomly initialised}
  
  int index_of_label_filled=-1 ;
  
   
	string string_main_hex; // hex digit string 
  string function_name, str2, str3, str4;
  array<int, 32> code = {0};
	array<int, 7> opcode = {0};
  array<int, 7> funct7 = {0};
  array<int, 3> funct3 = {0};
	array<int, 5> rd = {0}, rs1 = {0}, rs2 = {0};

	while (!fptr.eof()) {

		fptr >> string_main_hex;
		string string_main_binary= hexcode_to_binarycode(string_main_hex);	
    // hex to binary conversion of an instruction 
		for (int i = 31; i >= 0; i--) {
			code[i] = (int)(string_main_binary.c_str()[i]) - '0';
		}


    	for (int i = 0; i <=6; i++) {
			opcode[i] = code[i+25];
		}
		for (int i = 0; i <=2 ; i++) {
			funct3[i] = code[i +17];
		}
    	for (int i = 0; i <=6; i++) {
			funct7[i] = code[i];
		}

		function_search(opcode, funct3 , funct7, function_name);
   
    // R-type 
		if (function_name == "add" || function_name == "sub" || function_name == "and" || function_name == "or" || function_name == "xor" || function_name == "sll" || function_name == "srl" ||  function_name == "sra") {
			for(int i = 0; i < 5; i++) {
				rs2[i] = code[i + 7];
				rs1[i] = code[i + 12];
				rd[i] = code[i + 20];
			}
			register_decode(rd, str2);
			register_decode(rs1, str3);
			register_decode(rs2, str4);
			cout << function_name << " " << str2 << ", " << str3 << ", " << str4 << endl;
		}

    // I -type ( non load along with jalr)  
    	else if (function_name == "addi" || function_name == "andi" || function_name == "ori" || function_name == "xori" || function_name == "slli" || function_name == "srli" || function_name == "jalr" ) {
			array<int, 12> immediate = {0};
			int num;
			for(int i = 0; i < 5; i++) {
					rs1[i] = code[i + 12];
					rd[i] = code[i + 20];
			}
			for(int i = 0; i < 12; i++) {
				immediate[i] = code[i ];
			}
			register_decode(rd, str2);
			register_decode(rs1, str3);
			binary_to_decimal_12bit(immediate, &num);
			cout << function_name << " " << str2 << ", " << str3 << ", " << num << endl;
		}
		
	else if (function_name == "srai") {
               array<int, 7> shamt = {0};
               int num;
               for (int i = 0; i < 5; i++) {
                     rs1[i] = code[i + 12];
                     rd[i] = code[i + 20];
                 }
                for (int i = 0; i < 7; i++) {
                   shamt[i] = code[i + 20];
                  }
    register_decode(rd, str2);
    register_decode(rs1, str3);
    binary_to_decimal_7bit(shamt, &num);
    cout << function_name << " " << str2 << ", " << str3 << ", " << num << endl;
}	
   
   //I -type (load)
 
	else if (function_name == "ld" || function_name == "lw" || function_name == "lh" || function_name == "lb" || function_name == "lwu" || function_name == "lhu" || function_name == "lbu") {
			array<int, 12> immediate = {0};
			int num;
			for(int i = 0; i < 5; i++) {
					rs1[i] = code[i + 12];
					rd[i] = code[i + 20];
			}
			for(int i = 0; i < 12; i++) {
				immediate[i] = code[i ];
			}
			register_decode(rd, str2);
			register_decode(rs1, str3);
			binary_to_decimal_12bit(immediate, &num);

    	cout << function_name << " " << str2 << ", " << num << " (" << str3 << ")" << endl;
		}

    // S-type 
		else if ( function_name == "sd" || function_name == "sw" || function_name == "sh" || function_name == "sb" ) {
      array<int, 12> immediate = {0};
      int num;

			for(int i = 0; i < 5; i++) {
				rs2[i] = code[i + 7];
				rs1[i] = code[i + 12];
			}

      for(int i = 0; i <=6; i++) {
				immediate[i] = code[i ];
			}
      for(int i = 7; i <=11; i++) {
				immediate[i] = code[i+20-7 ];
			}

			register_decode(rs2, str2);
			register_decode(rs1, str3);

      binary_to_decimal_12bit(immediate, &num);
			
       cout << function_name << " " << str2 << ", " << num << " (" << str3 << ")" << endl;

		}

    // B-Type 
    else if (function_name == "beq" || function_name == "bne" || function_name == "blt" || function_name == "bge" || function_name == "bltu" || function_name == "bgeu" ) {
    
     array<int, 13> immediate = {0};
      int num_branch;

			for(int i = 0; i < 5; i++) {
				rs2[i] = code[i + 7];
				rs1[i] = code[i + 12];
			}
      
      immediate[0] = code[0];
      immediate[1] = code[24];

      for(int i = 2; i <= 7; i++) {
				immediate[i] = code[i-1];
			}
      for(int i = 8; i <= 11; i++) {
				immediate[i] = code[i+20-8 ];
			}
      immediate[12]=0;

			register_decode(rs1, str2);
			register_decode(rs2, str3);

      {
          num_branch = 0 ;    
       for(int i = 0 ; i < 13; i++)
              (num_branch) = ((num_branch) *2) + immediate[i] ;
          
      }
		    // assume num_branch is positive

			string  string_label_to_print; 
			
			int previous_label_taken =- 60; // randomly intialised
			for(int p=0;p<=index_of_label_filled ; p++)
			{
			  if(Labels_tracking[p] == num_branch)  
			      {string_label_to_print= strings_label_names[p];
			      previous_label_taken = 0;}
			 }
			
			if(previous_label_taken !=0 )
			{index_of_label_filled = index_of_label_filled + 1;
			Labels_tracking[index_of_label_filled] = num_branch;
			string_label_to_print= strings_label_names[index_of_label_filled]; }
			
    		cout << function_name << " " << str2 << ", " << str3 << ", " << string_label_to_print << endl;
    		
    	//	cout << function_name << " " << str2 << ", " << str3 << ", " << num_branch << endl;

		}
      
   
    //U -Type lui

    else if (function_name == "lui") {
			array<int, 20> immediate = {0};
			string hex_string;
			for(int i = 0; i <5 ; i++) {
					rd[i] = code[i + 20];
			}
			for(int i = 0; i <=19; i++) {
				immediate[i] = code[i ];
			}
			string binary_string ;
			for (int i: immediate) {
        binary_string.push_back(i + '0');
      }
			register_decode(rd, str2);
			hex_string= binary_to_hex(binary_string);
			cout << function_name << " " << str2 << ", 0x" <<hex_string<< endl;
		}

    // J -Type jal
			else if ( function_name == "jal") {
			
     array<int, 21> immediate = {0};
      int num_jal;

			for(int i = 0; i < 5; i++) {
				rd[i] = code[i + 20];
			}
      
      immediate[0] = code[0];


      for(int i = 1; i <= 8; i++) {
				immediate[i] = code[i+11];
			}
			immediate[9]=code[11];

      for(int i = 10; i <= 19; i++) {
				immediate[i] = code[i - 9 ];
			}
      immediate[20]=0;

			register_decode(rd, str2);
			
      {
          num_jal = 0 ;    
       for(int i = 0 ; i < 21; i++)
              (num_jal) = ((num_jal) *2) + immediate[i] ;
          
      }
      
    // assume num_jal is positive
      
      		string  string_label_to_print; 
			
			int previous_label_taken =- 60; // randomly intialised
			for(int p=0;p<=index_of_label_filled ; p++)
			{
			  if(Labels_tracking[p] == num_jal)  
			      {string_label_to_print= strings_label_names[p];
			      previous_label_taken = 0;}
			 }
			
			if(previous_label_taken !=0 )
			{index_of_label_filled = index_of_label_filled + 1;
			Labels_tracking[index_of_label_filled] = num_jal;
			string_label_to_print= strings_label_names[index_of_label_filled]; }
      
			
    		cout << function_name << " " << str2 << " ," << string_label_to_print << endl;
    		
			
    	//	cout << function_name << " " << str2 << ", " << num_jal << endl;

		}
      
      for(int j=0; j<19 ;j++ )
                   {Labels_tracking[j] -= 4 ; }
   
      
      for(int p=0 ; p<= index_of_label_filled ; p++)
       {
		if(Labels_tracking[p] == 0)  
			cout<<strings_label_names[p]<<": ";
			      }
      
 
      
		string_main_hex = function_name = str2 = str3 = str4 = '\0';
	}
		fptr.close();
  

  return 0;
}