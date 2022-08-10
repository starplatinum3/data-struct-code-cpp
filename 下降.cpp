// void ParseE(){

//     switch(lookahead){

//       case '(','i':

//         ParseT();

//         ParseE'();

//         break;

//       default:

//         print("syntax error \n");

//         exit(0);

//     }

//   }

//   void ParseE'(){

//     switch(lookahead){

//       case '+':

//         MatchToken('+');

//         ParseT();

//         ParseE'();

//         break;

//       case ')','#':

//         break;

//       default:

//         print("syntax error \n");

//         exit(0);

//     }

//   }

//   void ParseT(){ 

//     switch(lookahead){

//       case '(','i':

//         ParseF();

//         ParseT'();

//         break;

//       default:

//         print("syntax error \n");

//         exit(0);

//     }

//   }

//   void ParseT'(){

//     switch(lookahead){

//       case '*':

//         MatchToken('*');

//         ParseF();

//         ParseT'();

//         break;

//       case '+',')','#':

//         break;

//       default:

//         print("syntax error \n");

//         exit(0);

//     }

//   }

//   void ParseF(){

//     switch(lookahead){

//       case '(':

//         MatchToken('(');

//         ParseE();

//         MatchToken(')');

//         break;

//       case 'i':

//         MatchToken('i');

//         break;

//       default:

//         print("syntax error \n");

//         exit(0);

//     }

//   }