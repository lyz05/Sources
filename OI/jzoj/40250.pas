const
	Maxn=100005;
var
	Height,SA,Rank,Wv,Ws,x,y:array[0..Maxn]of longint;
	s:array[0..Maxn]of char;
	n,f,t:longint;
	Kth:int64;
procedure GetSA;
var
	Max,i,p,l:longint;
begin
	for i:=1 to n do
		x[i]:=ord(s[i]);
	Max:=0;
	for i:=1 to n do
	begin
		Wv[i]:=x[i];
		if Max<Wv[i] then
			Max:=Wv[i];
	end;
	for i:=0 to Max do
		Ws[i]:=0;
	for i:=1 to n do
		inc(Ws[Wv[i]]);
	for i:=1 to Max do
		inc(Ws[i],Ws[i-1]);
	for i:=n downto 1 do
	begin
		SA[Ws[Wv[i]]]:=i;
		dec(Ws[Wv[i]]);
	end;
	l:=1;
	while l<=n do
	begin
		p:=0;
		for i:=n-l+1 to n do
		begin
			inc(p);
			y[p]:=i;
		end;
		for i:=1 to n do
			if SA[i]>l then
			begin
				inc(p);
				y[p]:=SA[i]-l;
			end;
		Max:=0;
		for i:=1 to n do
		begin
			Wv[i]:=x[y[i]];
			if Max<Wv[i] then
				Max:=Wv[i];
		end;
		for i:=0 to Max do
			Ws[i]:=0;
		for i:=1 to n do
			inc(Ws[Wv[i]]);
		for i:=1 to Max do
			inc(Ws[i],Ws[i-1]);
		for i:=n downto 1 do
		begin
			SA[Ws[Wv[i]]]:=y[i];
			dec(Ws[Wv[i]]);
		end;
		for i:=1 to n do
		begin
			y[i]:=x[i];
			x[i]:=0;
		end;
		p:=1;
		x[SA[1]]:=1;
		for i:=2 to n do
		begin
			if (y[SA[i-1]]<>y[SA[i]]) or (y[SA[i-1]+l]<>y[SA[i]+l]) then
				inc(p);
			x[SA[i]]:=p;
		end;
		if p=n then
			break;
		l:=l<<1;
	end;
	for i:=1 to n do
		Rank[SA[i]]:=i;
end;

procedure GetHeight;
var
	i,j,k:longint;
begin
	k:=0;
	for i:=1 to n do
	begin
		if k>0 then
			dec(k);
		j:=SA[Rank[i]-1];
		while (i+k<=n) and (j+k<=n) and (s[i+k]=s[j+k]) do
			inc(k);
		Height[Rank[i]]:=k;
	end;
end;

procedure GetAns;
var
	i:longint;
	Now:int64;
begin
	f:=0;
	t:=0;
	Now:=0;
	for i:=1 to n do
		if Now+n-SA[i]+1-Height[i]<Kth then
			inc(Now,n-SA[i]+1-Height[i])
		else
		begin
			Now:=Kth-Now;
			f:=SA[i];
			t:=SA[i]+Height[i]+Now-1;
			break;
		end;
	if f=0 then
	begin
		f:=SA[n];
		t:=n;
	end;
end;

procedure Scanf;
var
	St:ansistring;
	i:longint;
begin
	assign(input,'4025.in');
	reset(input);
	readln(St);
	n:=length(St);
	for i:=1 to n do
		s[i]:=St[i];
	readln(Kth);
	//close(input);
end;

procedure Solve;
begin
	GetSA;
	GetHeight;
	GetAns;
end;

procedure Printf;
var
	i:longint;
begin
	//assign(output,'password.out');
	//rewrite(output);
	for i:=f to t do
		write(s[i]);
	writeln;
	//close(output);
end;

begin
	Scanf;
	Solve;
	Printf;
end.
