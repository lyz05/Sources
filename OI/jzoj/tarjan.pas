program tarjan;
var 
   v,f:array[1..100]of boolean;  
   dfn,low:array[1..100]of integer;  
   a:array[0..100,0..100]of integer;  
   i,j,n,m,x,y,deep,d:integer;  
   stack,ln:array[1..100]of integer;
{low：在DFS树中，设low[x]是x或x的后代能够达到的最高的 祖先。初始化时low[x]设为x。
 f: 判断当时某点是否在队列中
  d：记录时间戳}  
function min(x,y:longint):integer;  
begin 
     if x>y then exit(y)  
       else exit(x);  
end;  
procedure print(x:integer);  //出栈，打印  
begin 
     while stack[deep]<>x do 
       begin 
         write(stack[deep],' ');  
         f[stack[deep]]:=false;  
         dec(deep);  
       end;  
     writeln(stack[deep]);  
     f[stack[deep]]:=false;  //去除入栈标记  
     dec(deep);  
end;  
procedure dfs(x:integer);  
var 
     i:integer;  
begin 
     inc(d);  //时间  
     dfn[x]:=d;  //规则1  
     low[x]:=d;  
     inc(deep);  //栈中元素个数  
     stack[deep]:=x;  //规则2  
     f[x]:=true;  
     for i:=1 to a[x,0] do 
       if not v[a[x,i]] then 
         begin 
           v[a[x,i]]:=true;  
           dfs(a[x,i]);  
           low[x]:=min(low[a[x,i]],low[x]);  //规则3  
         end 
         else if f[a[x,i]] then 
                low[x]:=min(low[x],dfn[a[x,i]]);  //规则4  
       if dfn[x]=low[x] then  //规则5  
         print(x);  
end;  
begin 
 //assign(input,'3958.in');reset(input);
 //assign(output,'.out');rewrite(output);

   readln(n,m);  
   fillchar(a,sizeof(a),0);  
   for i:=1 to m do 
     begin 
       readln(x,y);		//读入图  
       inc(a[x,0]);  
       a[x,a[x,0]]:=y;		//有向图
       {inc(a[y,0]);
       a[y,a[y,0]]:=x;}
     end;
   for i:=1 to n do 
     if not v[i] then 
       begin 
         v[i]:=true;  
         dfs(i);		//更换起点，规则6  
       end;  
end.
