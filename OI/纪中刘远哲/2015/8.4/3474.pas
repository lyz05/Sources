uses	math;
const	size=200+5;mo=10;
type	hugeint=array[0..size] of int64;
var	s:string;
	i:longint;
	n,l,mid,r:hugeint;
function times(a,b:hugeint):hugeint;
var	i,j:longint;
	ans:hugeint;
begin
	fillchar(ans,sizeof(ans),0);
	for i:=1 to a[0] do 
		for j:=1 to b[0] do 
			ans[i+j-1]:=ans[i+j-1]+a[i]*b[j];
	for i:=1 to a[0]+b[0] do begin
		ans[i+1]:=ans[i+1]+ans[i] div mo;
		ans[i]:=ans[i] mod mo;
		if ans[a[0]+b[0]]>0 
			then ans[0]:=a[0]+b[0]
			else ans[0]:=a[0]+b[0]-1;
	end;
	times:=ans;
end;
function add(a,b:hugeint):hugeint;
var	i:longint;
	ans:hugeint;
begin
	fillchar(ans,sizeof(ans),0);
	ans[0]:=max(a[0],b[0]);
	for i:=1 to ans[0] do begin
		ans[i]:=ans[i]+a[i]+b[i];
		ans[i+1]:=ans[i+1]+ans[i] div mo;
		ans[i]:=ans[i] mod mo;
	end;
	if ans[ans[0]+1]>0 then inc(ans[0]);
	add:=ans;
end;
function average(a,b:hugeint):hugeint;
var	i:longint;
	ans:hugeint;
begin
	ans:=add(a,b);
	for i:=ans[0] downto 2 do begin
		ans[i-1]:=ans[i-1]+(ans[i] mod 2)*10;
		ans[i]:=ans[i]>>1;
	end;
	ans[1]:=ans[1]>>1;
	if ans[ans[0]]=0  then dec(ans[0]);
	average:=ans;
end;
function plustwo(a:hugeint):hugeint;
var	i:longint;
	ans:hugeint;
begin
	ans:=a;
	ans[1]:=ans[1]+2;
	i:=1;
	while (i<=ans[0]) and (ans[i]>=10) do begin
		ans[i+1]:=ans[i+1]+ans[i] div 10;
		ans[i]:=ans[i] mod 10;
	end;
	if ans[ans[0]+1]>0 then inc(ans[0]);
	plustwo:=ans;
end;
function over(a,b:hugeint):boolean;
var	i:longint;
begin
	if (a[0]<b[0]) then exit(false);
	if (a[0]>b[0]) then exit(true);
	for i:=a[0] downto 1 do begin
		if a[i]<b[i] then exit(false);
		if a[i]>b[i] then exit(true);
	end;
	exit(false);
end;
begin
	readln(s);
	fillchar(n,sizeof(n),0);
	n[0]:=length(s);
	for i:=1 to n[0] do 
		n[i]:=ord(s[n[0]-i+1])-ord('0');
	fillchar(l,sizeof(l),0);
	l[0]:=1;l[1]:=1;
	r:=n;
	repeat
		mid:=average(l,r);
		if over(times(mid,mid),n) then r:=mid else l:=mid;
	until over(plustwo(l),r);
	for i:=l[0] downto 1 do write(l[i]);
	writeln;
end.
