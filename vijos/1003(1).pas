const	maxn=26;
	alpha='ABCDEFGHIJKLMNOPQRSTUVWXYZ';
	mo=10007;
var	i,j,k,m,n,a,std,tmp:longint;
	s:array[0..maxn] of string;
	p:array[0..maxn] of boolean;
function work(s:string):longint;
	forward;
function calc(var s:string;pos:longint;id:char):longint;
var	s1,s2:string;
	i,t:longint;
begin
	calc:=1;
	s1:=copy(s,1,pos-1);
	s2:=copy(s,pos+1,length(s)-pos);
	case id of
		'+':calc:=work(s1)+work(s2);
		'-':calc:=work(s1)-work(s2);
		'*':calc:=work(s1)*work(s2);
		'^':for i:=1 to work(s2) do begin
			t:=work(s1);
			calc:=(calc*t) mod mo;
		end;
	end;
	calc:=calc mod mo;
end;
function work(s:string):longint;
var	i,t,len:longint;
	flag:boolean;
begin
	while  (s[1]='(') and (s[length(s)]=')') do begin
		delete(s,1,1);
		delete(s,length(s),1);
	end;

	len:=length(s);
	i:=len;
	while i>0 do begin
		if s[i]=')' then begin
			flag:=true;
		end;
		case s[i] of
	       		'+','-':exit(calc(s,i,s[i]));
			')':exit(calc(s,i+1,s[i+1]));
		end;
		dec(i);
	end;
	i:=len;
	while i>0 do begin
		case s[i] of
	       		'*':exit(calc(s,i,s[i]));
		end;
		dec(i);
	end;

	i:=len;
	while i>0 do begin
		case s[i] of
	       		'^':exit(calc(s,i,s[i]));
		end;
		dec(i);
	end;
	if s='a' then exit(a) else begin
		val(s,t);
		exit(t);
	end;
{
	t1:=pos('+',s);
	t2:=pos('-',s);
	if (t1=0) or (t2<t1) then exit(calc(s,t1,'-'));
	if (t2=0) or (t1<t2) then exit(calc(s,t2,'+'));
	t1:=pos('*',s);
	if t1<>0 then exit(calc(s,t1,'*'));
	t1:=pos('^',s);
	if t1<>0 then exit(calc(s,t1,'^'));
}
end;
procedure scanf(var s:string);
var	i:longint;
	ss:string;
begin
	s:='';
	readln(ss);
	for i:=1 to length(ss) do 
		if ss[i]<>' ' then s:=s+ss[i];
end;
begin
	assign(input,'1003.in');reset(input);
	//assign(output,'1003.out');rewrite(output);
	
	scanf(s[0]);
	readln(n);
	for i:=1 to n do begin
		scanf(s[i]);
		//s[i]:='('+s[i]+')'
	end;
	fillchar(p,sizeof(p),true);
	for a:=0 to 5 do begin
		std:=work(s[0]);
		for i:=1 to n do begin
			tmp:=work(s[i]);
			if tmp<>std then p[i]:=false;
		end;
	end;
	for i:=1 to n do 
		if p[i] then write(alpha[i]);
	writeln;
end.
