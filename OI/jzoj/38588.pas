var
        pri:array[1..3401]of longint;
        pd:array[1..31622]of boolean;
        ys:array[1..30,1..2]of longint;
        ps,k,n,t,i,j,m,phi:longint;
        ans,tot:int64;
{function f(x,y:longint):longint;
var
        t:longint;
begin
        repeat
                t:=x mod y;
                x:=y;
                y:=t;
        until t=0;
        exit(x);
end;}
procedure dfs(x:longint);
var
        i:longint;
        s:int64;
begin
        if x=k+1 then
        begin
                ans:=ans+tot*phi div 2;
                if tot=1 then ans:=ans+1;
                exit;
        end;
        dfs(x+1);
        s:=ys[x,1]-1;
        for i:=1 to ys[x,2] do
        begin
                tot:=tot*ys[x,1];
                phi:=phi*s;
                dfs(x+1);
                phi:=phi div s; 
                s:=s*ys[x,1];
        end;
        for i:=1 to ys[x,2] do begin tot:=tot div ys[x,1];end;
end;
procedure prepare;
begin
        for i:=2 to 31622 do
        if not pd[i] then
        begin
                inc(ps);
                pri[ps]:=i;
                for j:=2 to 31622 div i do
                pd[i*j]:=true;
        end;
end;
begin
        readln(t);
        prepare;
        for t:=1 to t do
        begin
                readln(n);
                k:=0;
                fillchar(ys,sizeof(ys),0);
                for i:=1 to ps do
                if n mod pri[i]=0 then
                begin
                        inc(k);
                        ys[k,1]:=pri[i];
                        while n mod pri[i]=0 do
                        begin
                                inc(ys[k,2]);
                                n:=n div pri[i];
                        end;
                        if n=1 then break;
                end;
			 
                if n>1 then
                begin
                        inc(k);
                        ys[k,1]:=n;
                        ys[k,2]:=1;
                end;
                tot:=1;
                ans:=0;
                phi:=1;
                dfs(1);
                writeln(ans);
        end;
end.
