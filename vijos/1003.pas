const	alpha='ABCDEFGHIJKLMNOPQRSTUVWXYZ';
var	i,j,k,m,n,std,tmp,tot,x:longint;
	st:string;
	s:array[1..26] of string;
	num:array[0..50] of longint;
	sym:array[1..50] of char;
	p:array[1..26] of boolean;
procedure push(var s:string;i:longint);
begin
	inc(tot);
	sym[tot]:=s[i];
end;
procedure pop;
var	p,i:longint;
	tmp:longint;
begin
	dec(tot);
	p:=tot;
	case sym[tot+1] of
		'+':num[p]:=num[p]+num[p+1];
		'-':num[p]:=num[p]-num[p+1];
		'*':num[p]:=num[p]*num[p+1];
		'^':
		begin
			tmp:=1;
			for i:=1 to num[p+1] do 
				tmp:=tmp*num[p];
			num[p]:=tmp;
		end;
	end;
end;
function can(var s:string;i:longint):boolean;
begin
	can:=true;
	if (s[i] in ['+','-']) and (sym[tot]<>'(') then exit;
	if (s[i] in ['*']) and (sym[tot] in ['*']) then exit;
	if (s[i]='^') and (sym[tot]='^') then exit;
	can:=false;
end;
function work(var s:string;a:longint):longint;
var	i:longint;
	t:string;
begin
	i:=1;
	tot:=0;
	while i<=length(s) do begin
		while s[i]='(' do begin
			push(s,i);
			inc(i);
		end;
		if s[i]='a' then begin
			num[tot]:=a;
			inc(i);	
		end else begin
			j:=i;
			repeat
				inc(i);
			until (s[i]<'0') or (s[i]>'9');
			t:=copy(s,j,i-j);
			val(t,num[tot]);
		end;
		repeat
			if s[i]=')' then begin
				while sym[tot]<>'(' do pop;
				dec(tot);
				num[tot]:=num[tot+1];
			end else begin
				while can(s,i) do pop;
				push(s,i);
			end;
			inc(i);
		until (i>length(s)) or (s[i-1]<>')');
	end;
	exit(num[0]);
end;
procedure scanf(var s:string);
var	i:longint;
begin
	readln(s);
	i:=1;
	while i<=length(s) do begin 
		if s[i]=' ' then delete(s,i,1) else inc(i);
	end;
	s:='('+s+')';
end;
begin
	assign(input,'1003.in');reset(input);

	scanf(st);
	readln(n);
	for i:=1 to n do scanf(s[i]);
	
	fillchar(p,sizeof(p),1);
	for x:=0 to 5 do begin
		std:=work(st,x);
		for i:=1 to n do begin
			tmp:=work(s[i],x);
			if std<>tmp then p[i]:=false;
		end;
	end;
	for i:=1 to n do 
		if p[i] then write(alpha[i]);
	writeln;
end.
hello world!
