var
    i,j,n,m,max1,x,y:integer;
    ans:array[0..500,0..100,0..100] of integer;
    fch:array[1..500] of 0..1;
    ch:char;
function min(x,y:integer):integer;
begin
    if x<y then exit(x);exit(y);
end;
function max(x,y:integer):integer;
begin
    if x>y then exit(x);exit(y);
end;
begin
    readln(n,m);
    for i:=1 to n do
    begin
        read(ch);
        if ch='j' then fch[i]:=0
        else fch[i]:=1;
    end;
    fillchar(ans,sizeof(ans),255);
    ans[1,0,0]:=0;
    ans[0,0,0]:=0;
    if fch[1]=1 then ans[1,0,1]:=0;
    for i:=2 to n do
    begin
        for x:=0 to min(m,i) do
        begin
            for y:=0 to min(m,i) do
            begin
                if fch[i]=0 then
                begin
                    ans[i,x,y]:=ans[i-1,x,y];
                    if (fch[i-1]=1)and(x>0)and(y>0)and(ans[i-2,x-1,y-1]<>-1) then
                    begin
                        ans[i,x,y]:=max(ans[i,x,y],ans[i-2,x-1,y-1]+1);
                    end;
                    if (fch[i-1]=0)and(x>0)and(ans[i-2,x-1,y]<>-1) then
                    ans[i,x,y]:=max(ans[i,x,y],ans[i-2,x-1,y]+1);
                end;
                if fch[i]=1 then
                begin
                    ans[i,x,y]:=ans[i-1,x,y];
                    if (fch[i-1]=1)and(y>0)and(ans[i-2,x,y-1]<>-1) then
                    begin
                        ans[i,x,y]:=max(ans[i,x,y],ans[i-2,x,y-1]+1);
                    end;
                    if (fch[i-1]=0)and(ans[i-2,x,y]<>-1) then
                    ans[i,x,y]:=max(ans[i,x,y],ans[i-2,x,y]+1);
                end;
            end;
        end;
    end;
    for i:=0 to m do if ans[n,i,i]>max1 then max1:=ans[n,i,i];
    writeln(max1);
end.
