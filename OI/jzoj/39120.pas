var
        ans,sum,j,next,n,m,n1:int64;
begin
        readln(N,m);
        ans:=m*n;
        if m>=n then m:=n;
        j:=1;
        while j<=m do begin
                n1:=n div j;
                next:=n div n1;
                if next>m then next:=m;
                sum:=(n div j)*(next+j)*(next-j+1) shr 1;
                ans:=ans-sum;
                j:=next+1;
        end;
        writeln(ans);
end.
