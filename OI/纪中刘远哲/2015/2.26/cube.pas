const	maxn=5;
var	i,j,k,m,n,ans,t:longint;
	a:array[1..maxn,1..maxn,1..6] of char;
	map:array[1..maxn,1..maxn,1..maxn] of char;
	//ch:char;
	s:string;
	//ǰ���������
procedure cut(x,y,z:longint);
var	i,t:longint;
begin
	case z of
		1,3:t:=3;
		2,4:t:=2;
		5,6:t:=1;
	end;
	case t of
		1:for i:=1 to n do map[i,x,y]:='!';
		2:for i:=1 to n do map[x,i,y]:='!';
		3:for i:=1 to n do map[x,y,i]:='!';
	end;
end;
begin
	//assign(input,'cube.in');reset(input);
	//assign(output,'cube.out');rewrite(output);
	
	while true do begin
		fillchar(map,sizeof(map),0);
		readln(n);
		if n=0 then exit;
		for i:=1 to n do begin
			readln(s);
			t:=0;
			for j:=1 to 6 do begin
				for k:=1 to n do begin
					inc(t);
					if (ord(s[t])=32) then
					begin
						inc(t);
					end;
					a[k,i,j]:=s[t];
					if a[k,i,j]='.' then cut(k,i,j);
				end;
			end;
		end;

		ans:=0;
		for i:=1 to n do
			for j:=1 to n do
				for k:=1 to n do
					if map[i,j,k]<>'!' then inc(ans);
		writeln('Maximum weight: ',ans,' gram(s)');
	end;
	//close(input);close(output);
end.
