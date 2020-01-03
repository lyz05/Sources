var     t,z,i:longint;
        ans,sum,n,m,nn,j,next:int64;
begin
	readln(n,m);
	ans:=n*m;
	if m>=n then m:=n;
	j:=1;
	while j<=m do begin
		nn:=n div j;
		next:=n div nn;
		if next>m then next:=m;
		sum:=(next+j)*(next-j+1) div 2*nn;
		dec(ans,sum);
		j:=next+1;
	end;
	writeln(ans);
end.
//close(input);close(output);
