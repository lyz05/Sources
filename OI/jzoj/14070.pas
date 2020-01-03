program Denver;
var
        i,n,m,x:Longint;
        a,dis:array[0..100001] of longint;
procedure dfs(x,y,z:longint);
var
        i,j,t:longint;
begin
        if x>y then exit;
        t:=y+1;
        for i:=x to y do
                if a[i]+i>=y+1 then
                begin
                        dis[i]:=z;
                        t:=i;
                        break;
                end;
        if t=y+1 then exit; 
        dfs(x,t-1,z+1);
        for i:=t+1 to y do
                if a[i]+i>=y+1 then dis[i]:=z
                else dis[i]:=z+1;
end;
begin
       // assign(input,'data8.in');reset(input);
       // assign(output,'data8.out');rewrite(output);
        readln(n,m);
        for i:=1 to n do
                read(a[i]);
        readln;
        dfs(1,n,1);
        for i:=1 to m do
        begin
                read(x);
                write(dis[x],' ');
        end;
        writeln;
      //  close(input);
end.
