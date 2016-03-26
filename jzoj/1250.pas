var	f:array[0..1000,1..2]of longint;
	c:array[1..1000,1..1000]of char;
        u:array[1..1000]of longint;
        n,m,i,j,k,x:longint;
        ans:int64; 
begin
	assign(input,'1250.in');reset(input);
	//assign(output,'.out');rewrite(output);

        readln(n,m);
        for i:=1 to n do
        begin
                for j:=1 to m do read(c[i,j]);
                readln;
        end;
        for i:=1 to n do
        begin
                for j:=1 to m do
                	if c[i,j]='*' then u[j]:=0 else u[j]:=u[j]+1;
                //更新当前位置向上能到的最远距离
		k:=0;
                for j:=1 to m do
                begin
                        while (k>0) and (f[k,1]>=u[j]) do dec(k);
			//节约空间，加快速度，过滤错误结点
                        inc(k);
                        f[k,1]:=u[j];
                        f[k,2]:=j;
                        //枚举每一行的举行个数
                        for x:=k downto 1 do
                        begin
                                ans:=ans+f[x,1]*(f[x,2]-f[x-1,2]);
                        end;
                end;
		//以当前结点为终点的矩形数量
        end;
        writeln(ans);
end.
