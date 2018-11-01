clear all;
img = imread('teste.jpg');
img = rgb2gray(img);

blur = [];
deblur = [];

for sizePSF = 3:2:7
    for i = 1:0.5:10
        blurIMG = imgaussfilt(img, i, 'FilterSize', sizePSF);
        blur(end + 1) = blurMetric(blurIMG);
        PSF = fspecial('gaussian',sizePSF,i);
        deblur(end + 1) = blurMetric(deconvlucy(blurIMG, PSF));
    end
end

valores = 1:0.5:10;
sizes = 3:2:7;