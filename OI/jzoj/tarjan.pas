program tarjan;
var 
   v,f:array[1..100]of boolean;  
   dfn,low:array[1..100]of integer;  
   a:array[0..100,0..100]of integer;  
   i,j,n,m,x,y,deep,d:integer;  
   stack,ln:array[1..100]of integer;
{low����DFS���У���low[x]��x��x�ĺ���ܹ��ﵽ����ߵ� ���ȡ���ʼ��ʱlow[x]��Ϊx��
 f: �жϵ�ʱĳ���Ƿ��ڶ�����
  d����¼ʱ���}  
function min(x,y:longint):integer;  
begin 
     if x>y then exit(y)  
       else exit(x);  
end;  
procedure print(x:integer);  //��ջ����ӡ  
begin 
     while stack[deep]<>x do 
       begin 
         write(stack[deep],' ');  
         f[stack[deep]]:=false;  
         dec(deep);  
       end;  
     writeln(stack[deep]);  
     f[stack[deep]]:=false;  //ȥ����ջ���  
     dec(deep);  
end;  
procedure dfs(x:integer);  
var 
     i:integer;  
begin 
     inc(d);  //ʱ��  
     dfn[x]:=d;  //����1  
     low[x]:=d;  
     inc(deep);  //ջ��Ԫ�ظ���  
     stack[deep]:=x;  //����2  
     f[x]:=true;  
     for i:=1 to a[x,0] do 
       if not v[a[x,i]] then 
         begin 
           v[a[x,i]]:=true;  
           dfs(a[x,i]);  
           low[x]:=min(low[a[x,i]],low[x]);  //����3  
         end 
         else if f[a[x,i]] then 
                low[x]:=min(low[x],dfn[a[x,i]]);  //����4  
       if dfn[x]=low[x] then  //����5  
         print(x);  
end;  
begin 
 //assign(input,'3958.in');reset(input);
 //assign(output,'.out');rewrite(output);

   readln(n,m);  
   fillchar(a,sizeof(a),0);  
   for i:=1 to m do 
     begin 
       readln(x,y);		//����ͼ  
       inc(a[x,0]);  
       a[x,a[x,0]]:=y;		//����ͼ
       {inc(a[y,0]);
       a[y,a[y,0]]:=x;}
     end;
   for i:=1 to n do 
     if not v[i] then 
       begin 
         v[i]:=true;  
         dfs(i);		//������㣬����6  
       end;  
end.
