uses    math;
var
        s,low,dfn,ans:array[0..50000] of int64;
        h,go,next:array[0..200000] of longint;
        bz:array[0..100000] of boolean;
        v,q:array[0..50000] of boolean;
        i,j,k,l,t,n,m,tot,top,time:longint;
procedure add(x,y:longint);
begin
        inc(tot);
        go[tot]:=y;
        next[tot]:=h[x];
        h[x]:=tot;
end;
function tarjan(x:longint):longint;
var
        t,l,j:longint;
begin
        inc(top);		//ջ��Ԫ�ظ���
        s[top]:=x;		//ѹ��Ԫ�ص�ջ��
        v[x]:=true;
        inc(time);		//ʱ��
        dfn[x]:=time;
        low[x]:=time;		//����1
        tarjan:=0;		//�������Ľ����
        t:=h[x];
        l:=n-1;			//ʣ��Ľ����
        while t<>0 do		//ö�ٵ�ǰ��ĸ���
        begin
                if not bz[(t+1) div 2] then
                begin
                        if not v[go[t]] then
                        begin
                                bz[(t+1) div 2]:=true;

                                j:=tarjan(go[t]);
                                inc(tarjan,j);
                                if low[go[t]]>=dfn[x] then	//���ʹ�����ͨ
                                begin
                                        ans[x]:=ans[x]+j*(l-j);	//(j,l-j)�鶼�ؾ���x
                                        l:=l-j;			//ȥ��
                                        repeat
                                                dec(top);	//popջ��Ԫ��
                                        until s[top+1]=go[t];
                                end;
                                low[x]:=min(low[x],low[go[t]]);
                                
				bz[(t+1) div 2]:=false;
                        end
                        else
                        begin
                                low[x]:=min(low[x],dfn[go[t]]);
                        end;
                end;
                t:=next[t];
        end;
        inc(tarjan);
        ans[x]:=ans[x]+n-1;	//��n-1�����Ǳؾ���
end;
begin
	//assign(input,'3958.in');reset(input);
	//assign(output,'.out');rewrite(output);

        readln(n,m);
        for i:=1 to m do
        begin
                readln(j,k);
                add(j,k);
                add(k,j);
        end;
        tarjan(1);
        for i:=1 to n do
                writeln(ans[i]);
end.

