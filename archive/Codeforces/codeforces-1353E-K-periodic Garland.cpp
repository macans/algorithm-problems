链接：https://www.nowcoder.com/questionTerminal/4060ac7e3e404ad1a894ef3e17650423?answerType=1&f=discussion
来源：牛客网

class Solution {
public:
    void replaceSpace(char* str, int length) {
        if(str == NULL || length <0)
            return;
        int num =0;    //空格数目
        for (int i = 0; i < length; i++){
            if (str[i] == ' ')
                num++;
        }
        char* p1 = &str[length -1];//原字符串指针
        char* p2 = &str[length -1 +num*2];//新字符串指针
        for (int i = length-1; i >= 0; i--) {
            if (str[i] == ' ') {
                *p2-- = '0';
                *p2-- = '2';
                *p2-- = '%';
                p1--;
            }else{
                *p2-- = *p1--;
            }
        }
    }
};
class Solution {
public:
	void replaceSpace(char *str,int length) {
        if(str == NULL || length == 0){
            return;
        }
        int cnt = 0;
        for(int i = 0; i < length; i++){
            if(str[i] == ' '){
                ++cnt;
            }
        }
        char* p = &str[length - 1];
        char* q = &str[length - 1 + (cnt << 1)];
        for(int i = length - 1; i >= 0; i--){
            if(str[i] == ' '){
                *q-- = '0';
                *q-- = '2';
                *q-- = '%';
                p--;
            } else{
                *q-- = *p--;
            }
        }
	}
};