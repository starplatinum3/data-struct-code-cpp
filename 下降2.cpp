// void ParseE()
// {
//     switch (lookahead)
//     {
//     case '(', 'i', '*':
//         ParseT();
//         ParseEP();
//         break;
//     default:
//         print("语法错误 \n");
//         exit(0);
//     }
// }

// void ParseEP()
// {
//     switch (lookahead)
//     {
//     case '+':
//         MatchToken('+');
//         ParseT();
//         ParseEP();
//         break;
//     case '#', ')':
//         break;
//     default:
//         print("语法错误 \n");
//         exit(0);
//     }
// }

// void ParseT()
// {
//     switch (lookahead)
//     {
//     case '(', 'i':
//         ParseF();
//         ParseTP();
//         break;
//     default:
//         print("语法错误 \n");
//         exit(0);
//     }
// }
// void ParseTP()
// {
//     switch (lookahead)
//     {
//     case '*':
//         MatchToken('*');
//         ParseF();
//         ParseTP();
//         break;
//     case '#', ')', '+':
//         break;
//     default:
//         print("语法错误 \n");
//         exit(0);
//     }
// }
// void ParseF()
// {
//     switch (lookahead)
//     {
//     case '(':
//         MatchToken('(');
//         ParseE();
//         MatchToken(')');
//         break;
//     case 'i':
//         MatchToken('i');
//         break;
//     default:
//         print("语法错误 \n");
//         exit(0);
//     }
// }