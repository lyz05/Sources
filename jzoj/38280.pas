uses math;
var
        x,y,xx,yy:array[0..4000] of longint;
        n,i,j,k,tot:longint;
        ans,a,b,c:extended;
        x2,y2:int64;
procedure qsort(l,r:longint);
var
        i,j:longint;
        x,y,t:real;
begin
        i:=l;
        j:=r;
        x:=xx[(i+j) div 2];
        y:=yy[(i+j) div 2];
        repeat
                while x*yy[i]>xx[i]*y do inc(i);
                while x*yy[j]<xx[j]*y do dec(j);
                if i<=j then
                begin
                        xx[0]:=xx[i];
                        xx[i]:=xx[j];
                        xx[j]:=xx[0];
                        yy[0]:=yy[i];
                        yy[i]:=yy[j];
                        yy[j]:=yy[0];
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if i<r then qsort(i,r);
        if l<j then qsort(l,j);
end;
begin
        read(n);
        for i:=1 to n do read(x[i],y[i]);
        for i:=1 to n do
        begin
                tot:=0;
                for j:=1 to n do
                        if (i<>j)and((y[i]<y[j])or((y[i]=y[j])and(x[j]>x[i]))) then
                        begin
                                inc(tot);
                                xx[tot]:=x[j]-x[i];
                                yy[tot]:=y[j]-y[i];
                        end;
                if tot<2 then continue;
                qsort(1,tot);
                x2:=0;
                y2:=0;
                for j:=1 to tot do
                begin
                        ans:=ans+x2*yy[j]-xx[j]*y2;
                        y2:=y2+yy[j];
                        x2:=x2+xx[j];
                end;
        end;
        writeln(ans/2:0:1);
end.
