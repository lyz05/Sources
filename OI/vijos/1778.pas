var k,s,ans:ansistring;
    lenk,lens,num,i,sum:longint;
    down:array[1..1000] of boolean; 
begin
	//assign(input,'readin.in'); reset(input);
	fillchar(down,sizeof(down),false);
	readln(k);
	readln(s);
	lenk:=length(k);lens:=length(s);
	num:=0;sum:=0;
	k:=upcase(k);
	for i:=1 to lens do //是否是小写，同时转成大写方便计算，虽然麻烦，但数据只有1000，时间可不计
	if ord(s[i])>ord('Z') then begin
		down[i]:=true;
		s[i]:=chr(ord(s[i])-32);
	end;
	for i:=1 to lens do begin
		inc(num);
		if num>lenk then num:=1;
		sum:=ord(k[num])-ord('A'); //需要偏移的位数
		sum:=ord(s[i])-sum; //偏移后的asc码
		if sum<65 then //若小于A要环形结构，+上26
		sum:=sum+26;
		ans:=ans+chr(sum); //记录，也可以直接判断输出
	end;

	for i:=1 to lens do //处理答案，输出，可以和上步结合。
	begin
		if down[i]=true then
			write(chr(ord(ans[i])+32))
		else
			write(ans[i]);
	end;
	writeln;
end.

var a:array[1..26,1..26] of char;
    i,j:longint;
    s,w,w1:ansistring;
begin
 //assign(input,'vigenere.in');assign(output,'vigenere.out');
 //reset(input);rewrite(output);

 for i:=1 to 26 do
  for j:=1 to 26 do
   if j+64+i-1>90 then
   a[i,j]:=chr(j+64+i-1-26) else
    a[i,j]:=chr(j+64+i-1);

  readln(w1);//length 100
  readln(s);//length 1000
  for i:=1 to length(s) div length(w1)+1 do  w:=w+w1;
  w:=upcase(w);

  for i:=1 to length(s) do begin
   j:=0;
   for j:=1 to 26 do if a[ord(w[i])-64,j]=upcase(s[i]) then break;
   if s[i]<='Z' then write(chr(j+64)) else write(chr(j+96));;
  end;

  //close(input);close(output);
end.
