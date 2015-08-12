uses	math;
const	maxn=30+1;
	list:array[1..3] of char=('T','L','R');
var	i,j,k,m,n:longint;
	v1,v2,v:int64;
	c:char;
	mi:array[1..maxn] of int64;
	s1,s2:string;
function get(x,y:char):char;
begin
	for i:=1 to 3 do 
		if (list[i]<>x) and (list[i]<>y) then exit(list[i]);
end;
function work(m:longint;s:string;c:char):int64;
var	i:longint;
	v:int64;
begin
	v:=0;
	for i:=m+1 to n do 
		if s[i]<>c then v:=v+mi[i];
	exit(v);
end;
begin
        assign(input,'tri.in');reset(input);
        //assign(output,'tri.out');rewrite(output);

	readln(n);
	readln(s1);
	readln(s2);
	mi[n]:=1;
	for i:=n-1 downto 1 do mi[i]:=mi[i+1]*2;

	if s1=s2 then writeln(0) else begin
		m:=1;
		while s1[m]=s2[m] do inc(m);
		if m=n-1 then writeln(1) else begin
			c:=get(s1[m],s2[m]);
                        v1:=work(m,s1,s2[m])+work(m,s2,s1[m])+1;
                        v2:=work(m,s1,c)+work(m,s2,c)+mi[m]+1;
			v:=min(v1,v2);
			writeln(v);
		end;
	end;

	close(input);close(output);
end.
