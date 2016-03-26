const	mo=10000;
var	i,j,k,m,n,t,tot,ans:longint;
	sz:array[1..100000+5] of longint;
	fh:array[1..100000+5] of char;
	ch:char;
begin
	assign(input,'1849.in');reset(input);
	//assign(output,'.out');rewrite(output);

	while not eof do begin
		t:=0;
		read(ch);
		while ch in ['0'..'9'] do begin
			t:=t*10+ord(ch)-48;
			read(ch);
		end;
		inc(tot);
		sz[tot]:=t;
		fh[tot]:=ch;
	end;
	for i:=1 to tot do begin
		if fh[i]='*' then begin
			sz[i+1]:=(sz[i+1]*sz[i]) mod mo;
			sz[i]:=0;
		end;
	end;
	for i:=1 to tot do 
		ans:=(ans+sz[i]) mod mo;
	writeln(ans);
end.
