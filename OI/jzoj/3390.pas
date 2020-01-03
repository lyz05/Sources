var     n,m,t1,t2,v,i,j,ans,tot,x1,y1:longint;
        kind,f:array[0..5001] of longint;
        x,y:array[0..50] of longint;
        time:array[0..2501] of real;
        p:array[0..5001] of boolean;
        len:array[0..51,0..51] of real;
        pd:boolean;
        ri,l,mid,t:real;
function check(x:longint):boolean;
var     i:longint;
begin
        if x=0 then exit(true);		//没有被选中
        for i:=1 to tot do		//扫描每个匹配点
                if (p[i]=false)and(time[i]+len[kind[i],x]/v<=mid) then begin
			//有边相连可以匹配,且在这次查找递归路径中没有尝试改变归属问题
			p[i]:=true;
                        if check(f[i]) then begin	//匹配点没有归属或者可以腾出位置
                                f[i]:=x;
                                exit(true);
                        end;
                end;
        exit(false);
end;
begin
	assign(input,'3390.in');reset(input);
        readln(n,m,t1,t2,v);
        for i:=1 to m do readln(x[i],y[i]);
        for i:=1 to n do begin
                readln(x1,y1);
                for j:=1 to m do len[i,j]:=sqrt(sqr(x[j]-x1)+sqr(y[j]-y1));
        end;
        l:=0;
        ri:=1e8;
        while ri-l>1e-8 do begin
                mid:=(ri+l)/2;
                tot:=0;
                for i:=1 to n do begin		//拆点
                        ans:=0;
                        t:=0;
                        while t+t1/60+t2<=mid do begin
                                inc(ans);
                                inc(tot);
                                kind[tot]:=i;
                                time[tot]:=(t1/60)*ans+t2*(ans-1);
                                t:=t+t1/60+t2;
                                if tot=i*m then break;
                        end;
                        if (t+t1/60<=mid) and (tot<i*m) then begin
                                inc(ans);
                                inc(tot);
                                kind[tot]:=i;
                                time[tot]:=(t1/60)*ans+t2*(ans-1);
                                t:=t+t1/60;
                        end;
                end;
                fillchar(f,sizeof(f),0);
                for i:=1 to m do begin
                        fillchar(p,sizeof(p),false);
                        pd:=check(i);
                        if not pd then begin
                                l:=mid;
                                break;
                        end;
                end;
                if pd then ri:=mid;
        end;
        writeln(ri:0:6);
end.
