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
				{����j�е�Ԫ�ص���2���ƻ�Ϊʮ����}
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
				{nowΪ��j�еı仯�����oldΪ�ڣ�j-1���б仯���}
				te:=now;
				now:=now xor(now shr 1)xor(now shr 2)xor(now shl 1)xor(now shl 2)xor old xor f[j];
{�����j�еĵ�i��Ԫ���б仯����j+1��ҲҪ����Ӧ�ı仯��now shr 1��ʾ�仯��j+1�е�i-1��Ԫ�أ�now shl 2��ʾ�仯��j+1�е�i+2��Ԫ�أ��������ƣ������j-1�еĵ�i��Ԫ���б仯����j+1�еĵ�i��Ԫ��ҲҪ�仯��xor old��������}
				now:=now and o;
				{����仯��Χ�������̵����}
				old:=te;
			end;
			if now=0 then 
				inc(ans);
			{�����n������仯����𰸼�1}
		end;
		writeln(ans);
	end;
end.
