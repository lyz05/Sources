var	m,n:set of 1..100;
	s,t,min,x,y,i,j,k,l,sum,p,ii:longint;
	a:array[1..100,1..100]of longint;
begin
	readln(p);
	for ii:=1 to p do
	begin
		k:=0; sum:=0;
		fillchar(a,sizeof(a),255);
		readln(x);
		m:=[1];
		n:=[2..x];
		for i:=1 to x do
		begin
			for j:=1 to x do
			begin
				read(a[i,j]);
				if a[i,j]=0 then a[i,j]:=maxlongint;
			end;
			readln;
		end;
		
		for l:=1 to x-1 do
		begin
			min:=maxlongint;
			for i:=1 to x do
				if i in m then begin
					for j:=1 to x do
					begin
						if (a[i,j]<min) and (j in n) then begin
						min:=a[i,j];
						s:=i;
						t:=j;
						end;
					end;
			end;
			sum:=sum+min;
			m:=m+[t];
			n:=n-[t];
			inc(k);
		end;
		writeln(sum);
	end;
end.
