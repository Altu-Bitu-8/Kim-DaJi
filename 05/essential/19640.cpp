#include<iostream>
#include<queue>

using namespace std;
typedef struct{
    int line;
    int idx;
    } dk;
typedef struct{
    int d;
    int h;
    int l;
    } p;
struct cmp{
    //근무일 d (내림차) -> 화장실이 급한 정도 h (내림차) -> 줄의 번호 l (오름차)
    bool operator()(const p &parent, const p &child){
        if(parent.d != child.d) return parent.d < child.d;
        else if(parent.h != child.h) return parent.h < child.h;
        else return parent.l > child.l;
    }
};    
void in(int line, priority_queue<p, vector<p>, cmp> &heads, vector<vector<p>> &lines){
    //l번째 줄의 사람이 선두로 들어온다
   heads.push(lines[line][0]);
}
int out(priority_queue<p, vector<p>, cmp> &heads, vector<vector<p>> &lines){
     //l번째 줄의 사람이 선두에서 나간다(화장실에 간다);
    int line = heads.top().l;
    heads.pop();
    lines[line].erase(lines[line].begin());
    return line;
}    
void setDekaLoc(int line, dk &deka){
    //데카가 서 있는 줄에서 데카의 순서 설정
    if(deka.idx > 0 && line == deka.line) {
        deka.idx--;
    }
}
bool isDekaOut(int line, dk &deka){
    //데카가 서 있는 줄에서 사람이 나가는데, 데카의 idx가 0인 경우 데카의 차례
    if(deka.idx == 0 && line == deka.line) return true;
    else return false;
}
int main()
{
    //입력
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<p>> lines(m); //m개의 줄
    
    int line;
    dk deka;
    p em;
    for(int i=0; i<n; i++){
        line = i % m;  
        em.l = line;
        cin >> em.d >> em.h;
        lines[line].push_back(em);
         if(i == k) {
            //데카 앞에 k명의 사람
           deka.line = line;
           deka.idx = lines[line].size()-1;
         }
    }
    //초기화
   priority_queue<p, vector<p>, cmp> heads;
   for(int i=0; i<m; i++){
   //*주의* 비어있는 줄에 접근할 수 있다!
      if (!lines[i].empty()) in(i, heads, lines);
   }
    //연산
   int out_line;
   int cnt = 0;
    while(true){
        out_line = out(heads, lines);
        cnt++;
        if(isDekaOut(out_line, deka)) break;
        //*주의* 비어있는 줄에 접근할 수 있다!
        if (!lines[out_line].empty()) in(out_line, heads, lines);
        setDekaLoc(out_line, deka);
    }
    //출력
    cout << cnt-1;
    return 0;
}