program vijos1390;
var 	n,m,t,tt,i,j,o,now,old,te,ans:longint;
	f:array[1..20]of longint;
	ch:char;
begin
	assign(input,'1389.in');reset(input);
	readln(n,m,t);
	for tt:=1 to t do
	begin
		for i:=1 to 20 do f[i]:=0;
		for i:=1 to n do
		begin
			for j:=1 to m do
			begin
				read(ch);
				if ch='1' then f[j]:=f[j]+(1 shl(i-1));
				{将第j列的元素当做2进制化为十进制}
			end;
			readln;
		end;
		readln;
		o:=1 shl n-1;
		ans:=0;
		for i:=0 to o do
		begin
			now:=i;
			old:=0;
			for j:=1 to m do
			begin
				{now为第j列的变化情况，old为第（j-1）列变化情况}
				te:=now;
				now:=now xor(now shr 1)xor(now shr 2)xor(now shl 1)xor(now shl 2)xor old xor f[j];
{如果第j列的第i个元素有变化，则j+1列也要做相应的变化（now shr 1表示变化第j+1列第i-1个元素，now shl 2表示变化第j+1列第i+2个元素，依此类推）如果第j-1列的第i个元素有变化，则j+1列的第i个元素也要变化（xor old）。。。}
				now:=now and o;
				{解决变化范围超出棋盘的情况}
				old:=te;
			end;
			if now=0 then 
				inc(ans);
			{如果第n列无需变化，则答案加1}
		end;
		writeln(ans);
	end;
end.
