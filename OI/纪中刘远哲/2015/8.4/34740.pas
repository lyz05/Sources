const size=200;
type hugeint=record
	len:integer;
	num:array[1..size] of integer;
	end;
var	s:string;
	i:integer;
	target,left,middle,right:hugeint;
function times(a,b:hugeint):hugeint;
var	i,j:integer;
	ans:hugeint;
begin
	fillchar(ans,sizeof(ans),0);
	for i:=1 to a.len do
		for j:=1 to b.len do
			ans.num[i+j-1]:=ans.num[i+j-1]+a.num[i]*b.num[j];
	for i:=1 to a.len+b.len do begin
		ans.num[i+1]:=ans.num[i+1]+ans.num[i] div 10;
		ans.num[i]:=ans.num[i] mod 10;
		if ans.num[a.len+b.len]>0
			then ans.len:=a.len+b.len
			else ans.len:=a.len+b.len-1;
	end;
	times:=ans;
end;
function add(a,b:hugeint):hugeint;
var	i:integer;
	ans:hugeint;
begin
	fillchar(ans,sizeof(ans),0);
	if a.len>b.len then ans.len:=a.len else ans.len:=b.len;
	for i:=1 to ans.len do begin
		ans.num[i]:=ans.num[i]+a.num[i]+b.num[i];
		ans.num[i+1]:=ans.num[i+1]+ans.num[i] div 10;
		ans.num[i]:=ans.num[i] mod 10;
	end;
	if ans.num[ans.len+1]>0 then inc(ans.len);
	add:=ans;
end;
function average(a,b:hugeint):hugeint;
var	i:integer;
	ans:hugeint;
begin
	ans:=add(a,b);
	for i:=ans.len downto 2 do begin
		ans.num[i-1]:=ans.num[i-1]+(ans.num[i] mod 2)*10;
		ans.num[i]:=ans.num[i] div 2;
	end;
	ans.num[1]:=ans.num[1] div 2;
	if ans.num[ans.len]=0 then dec(ans.len);
	average:=ans;
end;
function plustwo(a:hugeint):hugeint;
var	i:integer;
	ans:hugeint;
begin
	ans:=a;
	ans.num[1]:=ans.num[1]+2;
	i:=1;
	while (i<=ans.len) and (ans.num[i]>=10) do begin
		ans.num[i+1]:=ans.num[i+1]+ans.num[i] div 10;
		ans.num[i]:=ans.num[i] mod 10;
		inc(i);
	end;
	if ans.num[ans.len+1]>0 then inc(ans.len);
	plustwo:=ans;
end;
function over(a,b:hugeint):boolean;
var	i:integer;
begin
	if (a.len<b.len) then begin
		over:=false;
		exit;
	end;
	if (a.len>b.len) then begin
		over:=true;
		exit;
	end;
	for i:=a.len downto 1 do begin
		if a.num[i]<b.num[i] then begin
			over:=false;
			exit;	
		end;
		if a.num[i]>b.num[i] then begin
			over:=true;
			exit;
		end;
	end;
	over:=false;
end;
begin
	readln(s);
	fillchar(target.num,sizeof(target.num),0);
	target.len:=length(s);
	for i:=1 to target.len do
		target.num[i]:=ord(s[target.len-i+1])-ord('0');
	fillchar(left.num,sizeof(left.num),0);
	left.len:=1;
	left.num[1]:=1;
	right:=target;
	repeat
		middle:=average(left,right);
		if over(times(middle,middle),target)
			then right:=middle
			else left:=middle;
	until over(plustwo(left),right);
	for i:=left.len downto 1 do write(left.num[i]);
	writeln;
end.
