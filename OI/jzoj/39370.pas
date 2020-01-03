var
        n,b:longint;
        a,t:int64;
        f,g:array[0..3000,0..3000] of extended;
procedure search(x,y:longint);
begin
        if (x+y=n)or(x>a)or(y>b) then exit;
        if f[x,y]<>0 then exit;
        search(x+1,y);
        search(x,y+1);
        t:=((a-x)*2+b-y+1);
        f[x,y]:=2/(t+1)+(a-x)*2/(t+1)*f[x+1,y]+(b-y)/(t+1)*f[x,y+1];
        g[x,y]:=1/t+(a-x)*2/t*g[x+1,y]+(b-y)/t*g[x,y+1];
end;
begin
        read(n,a,b);
        search(0,0);
        writeln(f[0,0]:0:20);
        writeln(g[0,0]:0:20);
end.
