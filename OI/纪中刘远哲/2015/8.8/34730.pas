var	n,m:longint;
	f:array[1..100,1..12,0..(1<<12)] of int64;
function dp(h,l,s:integer):int64;
begin
        if f[h,l,s]=-1 then begin
                if h=n+1 then begin
                        if s=0 then f[h,l,s]:=1
                        else f[h,l,s]:=0;
                end else begin
                        f[h,l,s]:=0;
                        if s and 1<>0 then begin
                                if l<m then f[h,l,s]:=dp(h,l+1,s shr 1)
                                else f[h,l,s]:=dp(h+1,1,s shr 1);
                        end else begin
                                if l<m then inc(f[h,l,s],dp(h,l+1,s shr 1+mm))
                                else inc(f[h,l,s],dp(h+1,1,s shr 1+mm));
                                if (l<m)and(s and 2=0) then begin
                                        if l+1<m then inc(f[h,l,s],dp(h,l+2,s shr 2))
                                        else inc(f[h,l,s],dp(h+1,1,s shr 2));
                                end;
                        end;
                end;
        end;
        exit(f[h,l,s]);
end;
begin
	readln(n,m);
	writeln(dp(n,m,0));
end.
