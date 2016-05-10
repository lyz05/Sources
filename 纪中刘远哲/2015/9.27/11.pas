uses	math;
var	n,i,j,k,ans:longint;
	s:ansistring;		//change
begin
	assign(input,'string.in');reset(input);
	//assign(output,'string.out');rewrite(output);

	readln(s);
	n:=length(s);
	ans:=0;
	for i:=1 to n do begin
		j:=0;
		while (i+j<=n)and(i-j>=1)and(s[i+j]=s[i-j]) do inc(j);
		dec(j);
		ans := max(ans,j*2+1);
	end;
	for i:=1 to n-1 do begin
		j:=i;k:=i+1;
		while (j>=1)and(k<=n)and(s[j]=s[k]) do begin
			inc(k);
			dec(j);
		end;
		dec(k);inc(j);
		ans := max(ans,k-j+1);
	end;
	writeln(ans);

	//close(input);close(output);
end.

