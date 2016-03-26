const
        maxn=3005;
var
        n,a,b,i,j:longint;
        ansa,ansb,sa,sb:extended;
        sig:array[0..3005,0..3005]of extended;
begin
                readln(n,a,b);
                ansa:=0; ansb:=0;

                for i:=0 to n do 
			for j:=0 to n do sig[i][j]:=0;
                inc(a);
	       	sig[0][0]:=1;
                for i:=0 to a do
                begin
                        if i+1>n then break;
                        for j:=0 to b do
                        begin
                                if i+j+1>n then break;
                                sa:=a-i; sb:=b-j;
                                if i>0 then sig[i][j]:=sig[i-1][j]*2*sa/(sa+sa+2+sb);
                                if j>0 then sig[i][j]:=sig[i][j]+sig[i][j-1]*(sb+1)/(sa+sa+sb+1);
                                if i<a then ansa:=ansa+2/(sa+sa+sb)*sig[i][j];
                        end;
                end;

                dec(a); inc(b);
		for i:=0 to n do 
			for j:=0 to n do sig[i][j]:=0;
                sig[0][0]:=1;
                for i:=0 to a do
                begin
                        if i+1>n then break;
                        for j:=0 to b do
                        begin
                                if i+j+1>n then break;
                                sa:=a-i; sb:=b-j;
                                if i>0 then sig[i][j]:=sig[i-1][j]*2*(sa+1)/(sa+sa+2+sb);
                                if j>0 then sig[i][j]:=sig[i][j]+sig[i][j-1]*sb/(sa+sa+sb+1);
                                if j<b then ansb:=ansb+1/(sa+sa+sb)*sig[i][j];
                        end;
                end;

                writeln(ansa:0:16);
                writeln(ansb:0:16);

end.
