uses	math;
var	i,j,n,len:longint;
	s,ss:ansistring;
	p:array[0..300000] of longint;
	ch:char;
procedure pk;
var	i,mx,id:longint;
begin
	mx:=0;
	id:=0;
	for i:=2 to len-1 do begin
		if mx>i then
			p[i]:=min(p[2*id-i],mx-i)
		else
			p[i]:=1;
		while s[i+p[i]]=s[i-p[i]] do inc(p[i]);
		if p[i]+i>mx then begin
			mx:=p[i]+i;
			id:=i;
		end;
	end;
end;
function work:boolean;
var	i,t1,t2:longint;
begin
	i:=2;
	while i<=len do begin
		t1:=(i-1) div 2+1+1;
		t2:=(len-i) div 2+1+i-1;
		if (p[t1]=t1-1) and (p[t2]=t2-i+1) then exit(true);
		inc(i,2);
	end;
	exit(false);
end;
begin
	assign(input,'necklace.in');reset(input);
	assign(output,'necklace.out');rewrite(output);

	readln(n);
	i:=1;s:='';
	for j:=1 to n do begin
		s:='^#';
		readln(ss);
		for i:=1 to length(ss) do begin
			s:=s+ss[i]+'#';
		end;
		s:=s+'$';
			len:=length(s);
			pk;
			if work then writeln('YES') else writeln('NO');
	end;
	{	while i<=n do begin
		read(ch);
		if (ch>='a') and (ch<='z') then
			s:=s+'#'+ch
		else begin
			if s='' then continue;
			s:='^'+s+'#$';
			//writeln(s);
			len:=length(s);
			pk;
			if work then writeln('YES') else writeln('NO');
			s:='';
			inc(i);
			if ord(ch)=13 then continue else break;
		end;
	end;}
end.
