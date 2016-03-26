var
        i,sy,la:longint;
        su,ans,n:int64;
        ap:array[0..72] of boolean;
        f,sum,one:array[0..72] of int64;
procedure work(n:int64;qd:longint);
begin
        if n=0 then begin
                for i:=1 to sy do
				 if ap[i] then inc(su);
                exit;
        end;
        n:=n-1;
        inc(su,qd);
        for i:=1 to 72 do begin
                if sum[i]>n then begin
                        n:=n-sum[i-1];
                        inc(su,one[i-1]+sum[i-1]*qd);
                        break;
                end;
        end;
        ap[la-i+1]:=true;
        work(n,qd+1);
end;
begin
        readln(n);
        f[1]:=1;
        sum[1]:=1;
        one[1]:=1;
        f[2]:=1;
        sum[2]:=2;
        one[2]:=2;
        for i:=3 to 72 do begin
                f[i]:=sum[i-2]+1;
                sum[i]:=sum[i-1]+f[i];
                one[i]:=one[i-2]+sum[i-2]+1+one[i-1];
        end;
        for i:=1 to 72 do begin
                if ans+f[i]*i>=n then begin
                        inc(su,one[i-1]);
                        break;
                end;
                ans:=ans+f[i]*i;
        end;
        dec(n,ans);
        la:=i;
        sy:=n mod i;
        ap[1]:=true;
        work(n div i,1);
        writeln(su);
end.
