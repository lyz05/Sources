const	maxn=100+5;maxm=100+5;
var	i,j,k,m,n:longint;
	s:string;
	name:array[0..maxn,1..2] of string;
	score:array[1..maxm,1..2] of longint;
	st:array[1..maxm,1..4] of boolean;
	ans:array[0..maxn] of longint;
	ss:array[1..4] of string;
	ch:char;
procedure getst(s:string;x:longint);
var	i,j:longint;
begin
	for i:=1 to length(s) do begin
		j:=ord(s[i])-ord('A')+1;
		st[x][j]:=true;
	end;
end;
procedure work(j,x:longint);	//第j道题,第x个人
var	i,cnt,tot:longint;
	flag:boolean;
	sc:longint;
begin
	//ss[i,j] st[j,i]
	flag:=true;cnt:=0;tot:=0;
	for i:=1 to 4 do begin
		if st[j,i] then inc(tot);
		if (ss[i,j]='X') and (st[j,i]) then inc(cnt);
		if (ss[i,j]='X') and (not st[j,i]) then flag:=false;
	end;
	if (not flag) or (cnt=0) then begin
		sc:=0;
	end else
	if cnt=tot then sc:=score[j,1]
	else sc:=score[j,2];
	inc(ans[x],sc);
end;
procedure qsort(l,r:longint);
var	m,i,j:longint;
	m1,m2:string;
begin
	m:=ans[(l+r) div 2];m1:=name[(l+r) div 2,1];m2:=name[(l+r) div 2,2];
	i:=l;j:=r;
	repeat
		while (ans[i]>m) or ((ans[i]=m) and (name[i,1]<m1)) or 
	        ((name[i,1]=m1) and (name[i,2]<m2)) do inc(i);
		while (ans[j]<m) or ((ans[j]=m) and (name[j,1]>m1)) or 
	        ((name[j,1]=m1) and (name[j,2]>m2)) do dec(j);
		if i<=j then begin
			name[0]:=name[i];name[i]:=name[j];name[j]:=name[0];
			ans[0]:=ans[i];ans[i]:=ans[j];ans[j]:=ans[0];
			inc(i);dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;
begin
	assign(input,'1.in');reset(input);
	assign(output,'1.out');rewrite(output);

	readln(n,m);
	for i:=1 to n do begin
		readln(s);
		j:=pos(' ',s);
		name[i,1]:=copy(s,1,j-1);
		name[i,2]:=copy(s,j+1,length(s)-j);
		name[i,1]:=upcase(name[i,1]);
		name[i,2]:=lowercase(name[i,2]);
		for j:=1 to length(name[i,2]) do begin
			ch:=upcase(name[i,2][j]);
			name[i,2][j]:=ch;
			if (ord(ch)<>39) and (ch<>'-') then break;
		end;
	end;
	for i:=1 to m do begin
		read(score[i,1],score[i,2]);
		readln(s);
		delete(s,1,1);
		getst(s,i);
	end;
	for i:=1 to n do begin
		readln;
		for j:=1 to 4 do readln(ss[j]);
		for j:=1 to m do work(j,i);
	end;
	qsort(1,n);
	for i:=1 to n do begin
		writeln(ans[i],' ',name[i,1],' ',name[i,2]);
	end;
end.
