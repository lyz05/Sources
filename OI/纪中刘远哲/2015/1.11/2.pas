var	i,j,k,n,tot:longint;
	t1,t2,ans:int64;
begin
	tot:=0;
	readln(n,k);
	for i:=0 to n*k-2 do
		for j:=i+1 to n*k-1 do begin
			if (j-i) mod n=0  then inc(tot);
		end;

	t1:=1;t2:=1;
	t1:=t1<<(n*k-1);t2:=t2<<tot;
	ans:=t1-t2;
	writeln(ans);
end.