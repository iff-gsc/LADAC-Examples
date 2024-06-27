function momentOfInertiaPlot(xyz_cg_dist,xyz_dim,m,varargin)

alpha_mode_default = 'Density';
expected_alpha_modes = {'Density','Mass'};

p = inputParser;
addOptional(p,'Alpha',alpha_mode_default,@(x) any(validatestring(x,expected_alpha_modes)));

parse(p,varargin{:});

alpha_mode = p.Results.Alpha;


figure
view(3)
set(gca, 'YDir','reverse')
set(gca, 'ZDir','reverse')
axis equal
xlabel('x')
ylabel('y')
zlabel('z')
hold on
m_max = max(m);
volumes = prod(xyz_dim,2);
density_max = max(m(:)./volumes(:));
num_elems = size(xyz_cg_dist,1);
for i = 1:num_elems
    coord = xyz_cg_dist(i,:) + ...
        [ ...
        xyz_dim(i,1)/2, xyz_dim(i,2)/2, xyz_dim(i,3)/2; ...
        -xyz_dim(i,1)/2, xyz_dim(i,2)/2, xyz_dim(i,3)/2; ...
        -xyz_dim(i,1)/2, -xyz_dim(i,2)/2, xyz_dim(i,3)/2; ...
        xyz_dim(i,1)/2, -xyz_dim(i,2)/2, xyz_dim(i,3)/2; ...
        xyz_dim(i,1)/2, xyz_dim(i,2)/2, -xyz_dim(i,3)/2; ...
        -xyz_dim(i,1)/2, xyz_dim(i,2)/2, -xyz_dim(i,3)/2; ...
        -xyz_dim(i,1)/2, -xyz_dim(i,2)/2, -xyz_dim(i,3)/2; ...
        xyz_dim(i,1)/2, -xyz_dim(i,2)/2, -xyz_dim(i,3)/2 ...
        ];
    idx = [4 8 5 1 4; 1 5 6 2 1; 2 6 7 3 2; 3 7 8 4 3; 5 8 7 6 5; 1 4 3 2 1]';
    xc = coord(:,1);
    yc = coord(:,2);
    zc = coord(:,3);
    if strcmp(alpha_mode,'Density')
        alpha = 0.5*m(i)/volumes(i)/density_max;
    elseif strcmp(alpha_mode,'Mass')
        alpha = 0.5*m(i)/m_max;
    end
    patch(xc(idx), yc(idx), zc(idx), 'r', 'facealpha', alpha);
end
end