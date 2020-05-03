// преобразование выражение в постфиксную форму
std::string infx2pstfx(std::string inf)
{
  int i;
    for (i=0; i<strlen(expr_cls); i++) {
        switch (expr_cls[i]) {
            case '+': case '-': case '*': case '/': 
            return expr_cls[i]; break;
            default: break;
        }
    }
    return 0;
}
