function out = swap_loops(in, targ, rep)
%function to swap all occurrences of value t with value r in
%given matrix
    out = in;
    [r, c] = size(in);

    for i = 1:r
        for j = 1:c
            if out(i,j) == targ
                out(i,j) = rep;
            end
        end
    end
end