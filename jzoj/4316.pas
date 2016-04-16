var	i,j,k,m,n,now:longint;
	a:array[0..100001,1..26] of longint;
	s:ansistring;
	flag:boolean;
begin
	assign(input,'isfind.in');reset(input);
	//assign(output,'isfind.out');rewrite(output);

	readln(n,m);
	readln(s);
	for i:=n-1 downto 0 do begin
		a[i]:=a[i+1];
		a[i][ord(s[i+1])-ord('a')+1]:=i+1;
	end;
	for j:=1 to m do begin
		readln(s);
		now:=0;
		flag:=true;
		for i:=1 to length(s) do begin
			now:=a[now][ord(s[i])-ord('a')+1];
			if now=0 then begin
				flag:=false;
				break;
			end;
		end;
		if flag then writeln('Y') else writeln('N');
	end;

	close(input);close(output);
end.
