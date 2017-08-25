<?php

print render($form['form_id']);
print render($form['form_build_id']);
//$form = drupal_get_form('distributeurs_form');
//print drupal_render($form);
?>
<div class="row">
    <div class="col-sm-12" style="text-align: center">
        <p class="rtecenter">
            Cellfood&reg; vous plait,</p>
        <p class="rtecenter">
            Vous connaissez&nbsp; Cellfood&reg; , le n&deg;1 de l&rsquo;oxyg&eacute;nation cellulaire et ses bienfaits;<br />
            Vous souhaitez d&eacute;sormais le conseiller;<br />
            Vous partagez une approche hollistique de l&rsquo;individu;</p>
        <p class="rtecenter">
            Vous pouvez disposer d&rsquo;&eacute;l&eacute;ments&nbsp; scientifiques (7 publications m&eacute;dicales )<br />
            et d&rsquo;un dernier ouvrage qui traite de &quot;l&rsquo;oxyg&eacute;nation &agrave; la demande.&quot;</p>
        <p class="rtecenter">
            En retour de cette demande,&nbsp; vous recevrez en mail un dossier complet<br />
            - un plan de r&eacute;mun&eacute;ration-<br />
            et nous restons &agrave; votre disposition pour plus d&rsquo;informations<br />
            au <strong>05 58 47 16 50</strong> ou au <strong>06 73 57 00 34</strong>.</p>
        <p class="rtecenter">
            Cordialement,<br />
            Votre equipe cellfood Cellfood&reg;</p>
        <h3 class="rtecenter">
            &nbsp;</h3>
        <h3 class="rtecenter">
            Demande de dossier</h3>

    </div>
</div>
<div class="row">
    <div class="col-sm-9">
      <?php  print drupal_render($form['search']); ?>
    </div>
</div>
<div class="row">
    <div class="col-sm-6">
        <?php
        print render($form['infos-pro']);
        ?>
    </div>
    <div class="col-sm-6">
        <?php
        print render($form['adresse']);
        ?>
    </div>
</div>
<?php
print drupal_render_children($form);

?>

